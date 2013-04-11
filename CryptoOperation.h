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
//  CryptoOperation.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 29/03/13.
//
//

#ifndef __FireBreath__CryptoOperation__
#define __FireBreath__CryptoOperation__

#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include <queue>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>

#include "Algorithm.h"
#include "Key.h"

class CryptoOperation : public FB::JSAPIAuto
{
public:
    CryptoOperation(const FB::BrowserHostPtr& host, const boost::shared_ptr<Key>& key, const boost::shared_ptr<Algorithm>& algorithm);
    
    virtual ~CryptoOperation() {};
        
    void process(const std::string& bufferBase64);
    
    void finish();
    
    void abort();
    
    boost::shared_ptr<Key> get_key();
    boost::shared_ptr<Algorithm> get_algorithm();
    
    void set_result(FB::variant result);
    FB::variant get_result();
    
    
protected:
    virtual void processImpl(const char *buffer, unsigned long size) = 0;
    virtual void finishImpl() = 0;
        
protected:
    FB::BrowserHostPtr m_host;
    
private:
    boost::shared_ptr<Key> m_key;
    boost::shared_ptr<Algorithm> m_algorithm;
    FB::variant m_result;
    
    std::queue<std::string> m_processQueue;
    bool m_finish, m_abort;
    
    boost::thread  m_thread;
    boost::condition_variable m_cond;
    boost::mutex m_mut;

    void initializePropertiesAndMethods();
    void processQueue();
};

#endif /* defined(__FireBreath__CryptoOperation__) */
