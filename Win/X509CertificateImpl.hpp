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
//  X509CertificateImpl.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#ifndef __FireBreath__X509CertificateImpl__
#define __FireBreath__X509CertificateImpl__

#include "../X509Certificate.h"

class X509CertificateImpl: public X509Certificate
{
public:
    X509CertificateImpl(const FB::BrowserHostPtr& host, std::string name);
    virtual ~X509CertificateImpl() {};
    
    X509CertificateImpl(const X509CertificateImpl& other);
    X509CertificateImpl& operator=(const X509CertificateImpl& other);
    
    virtual FB::JSAPIPtr get_issuerX500Principal();
    virtual FB::FBDateString get_notAfter();
    virtual FB::FBDateString get_notBefore();
	virtual FB::JSAPIPtr get_privateKey();
    virtual std::string get_serialNumber();
    virtual FB::JSAPIPtr get_subjectX500Principal();
    virtual long get_version();
    virtual FB::VariantList get_keyUsage(); // See rfc5280 for more information
};

#endif /* defined(__FireBreath__X509CertificateImpl__) */
