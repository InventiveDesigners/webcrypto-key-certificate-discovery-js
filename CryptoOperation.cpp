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

#include "Base64.h"

CryptoOperation::CryptoOperation(const FB::BrowserHostPtr& host, const boost::shared_ptr<Key>& key, const boost::shared_ptr<Algorithm>& algorithm): m_host(host), m_key(key), m_algorithm(algorithm), m_finish(false), m_abort(false)
{
    initializePropertiesAndMethods();
}


void CryptoOperation::initializePropertiesAndMethods()
{
    registerProperty("onabort",  make_property(this, &CryptoOperation::get_onabort, &CryptoOperation::set_onabort));
    registerProperty("onerror",  make_property(this, &CryptoOperation::get_onerror, &CryptoOperation::set_onerror));
    registerProperty("onprogress",  make_property(this, &CryptoOperation::get_onprogress, &CryptoOperation::set_onprogress));
    registerProperty("oncomplete",  make_property(this, &CryptoOperation::get_oncomplete, &CryptoOperation::set_oncomplete));
    registerProperty("result",  make_property(this, &CryptoOperation::get_result));
    registerProperty("key",  make_property(this, &CryptoOperation::get_key));
    registerProperty("algorithm",  make_property(this, &CryptoOperation::get_algorithm));
    
    registerMethod("process",      make_method(this, &CryptoOperation::process));
    registerMethod("finish",      make_method(this, &CryptoOperation::finish));
    registerMethod("abort",      make_method(this, &CryptoOperation::abort));

}

void CryptoOperation::set_onerror(const FB::JSObjectPtr& onerror)
{
    m_onerror = onerror;
}

FB::JSObjectPtr CryptoOperation::get_onerror()
{
    return m_onerror;
}

void CryptoOperation::set_onabort(const FB::JSObjectPtr& onabort)
{
    m_onabort = onabort;
}

FB::JSObjectPtr CryptoOperation::get_onabort()
{
    return m_onabort;
}

void CryptoOperation::set_onprogress(const FB::JSObjectPtr& onprogress)
{
    m_onprogress = onprogress;
}

FB::JSObjectPtr CryptoOperation::get_onprogress()
{
    return m_onprogress;
}

void CryptoOperation::set_oncomplete(const FB::JSObjectPtr& oncomplete)
{
    m_oncomplete = oncomplete;
}

FB::JSObjectPtr CryptoOperation::get_oncomplete()
{
    return m_oncomplete;
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

void CryptoOperation::callOnComplete() const
{
    if (m_oncomplete)
        m_oncomplete->InvokeAsync("", FB::variant_list_of());
}

void CryptoOperation::callOnAbort() const
{
    if (m_onabort)
        m_onabort->InvokeAsync("", FB::variant_list_of());
}

void CryptoOperation::callOnProgress() const
{
    if (m_onprogress)
        m_onprogress->InvokeAsync("", FB::variant_list_of());
}

void CryptoOperation::callOnError() const
{
    if (m_onerror)
        m_onerror->InvokeAsync("", FB::variant_list_of());
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
        callOnAbort();
        return;
    }
    
    if (m_finish)
    {
        finishImpl();
    }
}
