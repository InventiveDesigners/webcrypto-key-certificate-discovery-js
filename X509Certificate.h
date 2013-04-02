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
//  X509Certificate.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 22/03/13.
//
//

#ifndef H_X509Certificate
#define H_X509Certificate

#include <string>

#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "X500Principal.h"


class X509Certificate : public FB::JSAPIAuto
{
public:
    X509Certificate(const FB::BrowserHostPtr& host, std::string name);
    virtual ~X509Certificate() {};
    
    X509Certificate(const X509Certificate& other);
    X509Certificate& operator=(const X509Certificate& other);
    
    virtual FB::JSAPIPtr get_issuerX500Principal() = 0;
    virtual FB::FBDateString get_notAfter() = 0;
    virtual FB::FBDateString get_notBefore() = 0;
    //get_publicKey
    //get_privateKey
    virtual std::string get_serialNumber() = 0;
    virtual FB::JSAPIPtr get_subjectX500Principal() = 0;
    virtual long get_version() = 0;
    virtual FB::VariantList get_keyUsage() = 0; // See rfc5280 for more information
    // get_extendedKeyUsage; // See rfc5280 for more information
    
    
protected:
    FB::BrowserHostPtr m_host;

private:
    void initializeProperties();
};


#endif
