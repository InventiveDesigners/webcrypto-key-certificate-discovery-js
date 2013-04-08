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
//  X509CertificateMac.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#ifndef __FireBreath__X509CertificateMac__
#define __FireBreath__X509CertificateMac__

#include "../X509Certificate.h"

#include "../X500Principal.h"

#include <Security/Security.h>
#include <string>
#include <map>



class X509CertificateMac: public X509Certificate
{
public:
    X509CertificateMac(const FB::BrowserHostPtr& host, SecCertificateRef cert_ref, boost::shared_ptr<SecKeyRef> privateKey_ref,X500Principal issuerX500Principal, X500Principal subjectX500Principal, int version, std::string validityNotBefore, std::string validityNotAfter, std::string serialNumber);
    virtual ~X509CertificateMac() { CFRelease(m_cert_ref); };
        
    static boost::shared_ptr<X509Certificate> createX509CertificateMac(const FB::BrowserHostPtr& host, SecCertificateRef cert_ref, SecKeyRef privateKeyRef);
    
    virtual FB::JSAPIPtr get_issuerX500Principal();
    virtual FB::FBDateString get_notAfter();
    virtual FB::FBDateString get_notBefore();
    virtual FB::JSAPIPtr get_privateKey();
    virtual std::string get_serialNumber();
    virtual FB::JSAPIPtr get_subjectX500Principal();
    virtual long get_version();
    virtual FB::VariantList get_keyUsage(); // See rfc5280 for more information
    
private:
    SecCertificateRef m_cert_ref;
    boost::shared_ptr<SecKeyRef> m_privateKey_ref;
    
    long m_version;
    std::string m_validityNotBefore;
    std::string m_validityNotAfter;
    std::string m_serialNumber;
    X500Principal m_issuerX500Principal;
    X500Principal m_subjectX500Principal;
     
    static std::map<std::wstring,std::wstring> m_oid_to_str;
    
    // Helper methods
    static std::string extractName(SecCertificateRef cert_ref);
    static std::string extractDateTime(CFDictionaryRef vals, CFTypeRef dateTimeRef);
    static X500Principal convertToX500Principal(const FB::BrowserHostPtr& host, CFArrayRef x500PrincipalRef);
    
    static std::map< std::wstring, std::wstring > createOIDtoStringMapping();
    
    static void releaseCFTypeRef(CFTypeRef* cf);
};

#endif /* defined(__FireBreath__X509CertificateMac__) */
