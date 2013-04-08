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
//  X509Certificate.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 22/03/13.
//
//

#include "X509Certificate.h"

X509Certificate::X509Certificate(const FB::BrowserHostPtr& host, std::string name) : JSAPIAuto(name), m_host(host)
{
    initializeProperties();
}

void X509Certificate::initializeProperties()
{
    registerProperty("issuerX500Principal",  make_property(this, &X509Certificate::get_issuerX500Principal));
    
    // TODO register notAfter and notBefore (type is commented out)
    //registerProperty("notAfter",  make_property(this, &X509Certificate::get_notAfter));
    //registerProperty("notBefore",  make_property(this, &X509Certificate::get_notBefore));
    // registerProperty("publicKey",  make_property(this, &X509Certificate::get_publicKey));
    registerProperty("privateKey",  make_property(this, &X509Certificate::get_privateKey));
    registerProperty("serialNumber",  make_property(this, &X509Certificate::get_serialNumber));
    registerProperty("subjectX500Principal",  make_property(this, &X509Certificate::get_subjectX500Principal));
    registerProperty("version",  make_property(this, &X509Certificate::get_version));
    registerProperty("keyUsage",  make_property(this, &X509Certificate::get_keyUsage)); // See rfc5280 for more information
    // registerProperty("extendedKeyUsage",  make_property(this, &X509Certificate::get_extendedKeyUsage)); // See rfc5280 for more information
}

