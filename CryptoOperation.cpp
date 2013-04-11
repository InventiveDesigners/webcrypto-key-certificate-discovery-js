// Copyright 2013 Inventive Designers
//
//  Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
//  CryptoOperation.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 29/03/13.
//
//

#include "CryptoOperation.h"
#include "JSEvent.h"

#include "Base64.h"

CryptoOperation::CryptoOperation(const FB::BrowserHostPtr& host, const boost::shared_ptr<Key>& key, const boost::shared_ptr<Algorithm>& algorithm): m_host(host), m_key(key), m_algorithm(algorithm), m_finish(false), m_abort(false)
{
    initializePropertiesAndMethods();
}


void CryptoOperation::initializePropertiesAndMethods()
{
    registerEvent("oncomplete");
    registerEvent("onerror");
    registerEvent("onprogress");
    registerEvent("onabort");

    registerProperty("result",  make_property(this, &CryptoOperation::get_result));
    registerProperty("key",  make_property(this, &CryptoOperation::get_key));
    registerProperty("algorithm",  make_property(this, &CryptoOperation::get_algorithm));
    
    registerMethod("process",      make_method(this, &CryptoOperation::process));
    registerMethod("finish",      make_method(this, &CryptoOperation::finish));
    registerMethod("abort",      make_method(this, &CryptoOperation::abort));

}


boost::shared_ptr<Key> CryptoOperation::get_key()
{
    return m_key;
}

boost::shared_ptr<Algorithm> CryptoOperation::get_algorithm()
{
    return m_algorithm;
}

FB::variant CryptoOperation::get_result()
{
    return m_result;
}

void CryptoOperation::set_result(FB::variant result)
{
    m_result = result;
}

void CryptoOperation::process(const std::string& bufferBase64)
{
    if (m_thread.get_id() == boost::thread::id())
    {
        m_thread = boost::thread(&CryptoOperation::processQueue, this);
    }
    
    {
        boost::lock_guard<boost::mutex> lock(m_mut);
        m_processQueue.push(bufferBase64);
    }
    m_cond.notify_one();
}

void CryptoOperation::finish()
{
    {
        boost::lock_guard<boost::mutex> lock(m_mut);
        m_finish = true;
    }
    m_cond.notify_one();
}

void CryptoOperation::abort()
{
    {
        boost::lock_guard<boost::mutex> lock(m_mut);
        m_abort = true;
    }
    m_cond.notify_one();
}

void CryptoOperation::processQueue()
{
    {
        boost::unique_lock<boost::mutex> lock(m_mut);
        while (!m_processQueue.empty() || !m_finish)
        {
            while(m_processQueue.empty() && !m_finish && !m_abort)
            {
                m_cond.wait(lock);
            }
            
            if (m_abort)
            {
                break;
            }
            
            if (!m_processQueue.empty())
            {
                std::string dataBase64 = m_processQueue.front();
                m_processQueue.pop();
                lock.unlock();
                int length;
                char* data = Base64::decode(dataBase64, &length);
                processImpl(data, length);
                delete[] data;
                lock.lock();
            }
        }
    }
    
    if (m_abort)
    {
        FireJSEvent("onabort", FB::VariantMap(), FB::variant_list_of());
        return;
    }
    
    if (m_finish)
    {
        finishImpl();
    }
}
