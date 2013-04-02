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
//  X509CertificateMac.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#include "X509CertificateMac.h"


#include "MacUtils.h"

#include <sstream>

std::map<std::wstring,std::wstring> X509CertificateMac::m_oid_to_str = X509CertificateMac::createOIDtoStringMapping();

X509CertificateMac::X509CertificateMac(const FB::BrowserHostPtr& host, SecCertificateRef cert_ref, X500Principal issuerX500Principal, X500Principal subjectX500Principal, int version, std::string validityNotBefore, std::string validityNotAfter, std::string serialNumber) : X509Certificate(host, extractName(cert_ref)), m_cert_ref(cert_ref), m_issuerX500Principal(issuerX500Principal), m_subjectX500Principal(subjectX500Principal), m_version(version), m_validityNotBefore(validityNotBefore), m_validityNotAfter(validityNotAfter), m_serialNumber(serialNumber)
{
    
                                          
                                          //MacUtils::CFStringRefToStringUsingUTF8String
    
    /*
     CFArrayRef values;
     CFDictionaryRef dict;
     dict = CFDictionaryGetValue(vals, kSecOIDBasicConstraints );
    values = dict ? CFDictionaryGetValue(dict, kSecPropertyKeyValue) : NULL;
    if (values) {
        for(int i = 0; i < CFArrayGetCount(values); i++) {
            CFDictionaryRef subDict = CFArrayGetValueAtIndex(values, i);
            
            // We cannot find OID defines for the CA - so rely on the lower libraries to give us a string
            // of sorts. Not a good idea - as now this code can be foiled by a actual string.
            //
            NSString *k = [NSString stringWithFormat:@"%@", CFDictionaryGetValue(subDict, kSecPropertyKeyLabel)];
            NSString *v = [NSString stringWithFormat:@"%@", CFDictionaryGetValue(subDict, kSecPropertyKeyValue)];
            if ([@"Certificate Authority" isEqualToString:k] && [@"Yes" isEqualToString:v]) {
                isCA = TRUE;
            }
        }
    };
    
    // Fall back on a simple self-sign check if there where no kSecOIDBasicConstraints.
    // set on the cert. Note that it is a DN is equal check - in some cases
    // doing a 509v3 Subject/Authority Key Identifier may be better ?? XXXX
    //
    if (!isCA && !values) {
        dict = CFDictionaryGetValue(vals, kSecOIDX509V1SubjectName);
        values = dict ? CFDictionaryGetValue(dict, kSecPropertyKeyValue) : NULL;
        subject = [NSString stringWithFormat:@"%@", values];
        
        dict = CFDictionaryGetValue(vals, kSecOIDX509V1IssuerName);
        values = dict ? CFDictionaryGetValue(dict, kSecPropertyKeyValue) : NULL;
        issuer = [NSString stringWithFormat:@"%@", values];
        
        // Crap way of secondgessing CA ness.
        if ([issuer isEqualToString:subject])
            isCA = TRUE;
    };
    
    SecPolicyRef policy = SecPolicyCreateBasicX509(); // SecPolicyCreateSSL(YES,nil);
    CFArrayRef chain = CFArrayCreate(NULL, (const void**)(&certificateRef), 1, NULL);
    
    SecTrustRef trustRef;
    SecTrustCreateWithCertificates(chain, policy, &trustRef);
    
    SecTrustResultType result;
    SecTrustEvaluate (trustRef, &result);
    
    if(result == kSecTrustResultProceed) {
        isUserTrust = TRUE;
        isInvalid = FALSE;
    } else
        if (result == kSecTrustResultUnspecified)
            isInvalid = FALSE;
    
    CFRelease(trustRef);
    CFRelease(chain);*/
}

X509CertificateMac::X509CertificateMac(const X509CertificateMac& other) : X509Certificate(other.m_host, extractName(other.m_cert_ref)), m_cert_ref(other.m_cert_ref),m_issuerX500Principal(other.m_issuerX500Principal), m_subjectX500Principal(other.m_subjectX500Principal), m_version(other.m_version), m_validityNotBefore(other.m_validityNotBefore), m_validityNotAfter(other.m_validityNotAfter), m_serialNumber(other.m_serialNumber)
{
}

X509CertificateMac& X509CertificateMac::operator=(const X509CertificateMac& other)
{
    X509Certificate::operator=(other);
    
    m_cert_ref = other.m_cert_ref;
    m_issuerX500Principal = other.m_issuerX500Principal;
    m_subjectX500Principal = other.m_subjectX500Principal;
    m_version = other.m_version;
    m_validityNotBefore = other.m_validityNotBefore;
    m_validityNotAfter = other.m_validityNotAfter;
    m_serialNumber = other.m_serialNumber;
    
    return *this;
}

boost::shared_ptr<X509Certificate> X509CertificateMac::createX509CertificateMac(const FB::BrowserHostPtr& host, SecCertificateRef cert_ref)
{
    const void *keys[] = { /*kSecOIDX509V1CertificateIssuerUniqueId, kSecOIDX509V1CertificateSubjectUniqueId, */kSecOIDX509V1IssuerName, /*kSecOIDX509V1IssuerNameLDAP, kSecOIDX509V1IssuerNameStd, */kSecOIDX509V1SerialNumber, kSecOIDX509V1Signature, /*kSecOIDX509V1SignatureAlgorithm, kSecOIDX509V1SignatureAlgorithmParameters, kSecOIDX509V1SignatureAlgorithmTBS, kSecOIDX509V1SignatureCStruct, kSecOIDX509V1SignatureStruct, */kSecOIDX509V1SubjectName, /*kSecOIDX509V1SubjectNameCStruct, kSecOIDX509V1SubjectNameLDAP, kSecOIDX509V1SubjectNameStd, */kSecOIDX509V1SubjectPublicKey, /*kSecOIDX509V1SubjectPublicKeyAlgorithm, kSecOIDX509V1SubjectPublicKeyAlgorithmParameters, kSecOIDX509V1SubjectPublicKeyCStruct, */kSecOIDX509V1ValidityNotAfter, kSecOIDX509V1ValidityNotBefore, kSecOIDX509V1Version/*, kSecOIDX509V3Certificate*/ };
    CFArrayRef keySelection = CFArrayCreate(NULL, keys , sizeof(keys)/sizeof(keys[0]), &kCFTypeArrayCallBacks);
    CFDictionaryRef vals = SecCertificateCopyValues(cert_ref, keySelection, NULL);
    
    
    X500Principal issuerX500Principal = convertToX500Principal(host, (CFArrayRef)CFDictionaryGetValue((CFDictionaryRef)CFDictionaryGetValue(vals, kSecOIDX509V1IssuerName), kSecPropertyKeyValue));
    X500Principal subjectX500Principal = convertToX500Principal(host, (CFArrayRef)CFDictionaryGetValue((CFDictionaryRef)CFDictionaryGetValue(vals, kSecOIDX509V1SubjectName), kSecPropertyKeyValue));
    int version = CFStringGetIntValue((CFStringRef)CFDictionaryGetValue((CFDictionaryRef)CFDictionaryGetValue(vals, kSecOIDX509V1Version), kSecPropertyKeyValue));
    std::string validityNotBefore = extractDateTime(vals, kSecOIDX509V1ValidityNotBefore);
    std::string validityNotAfter = extractDateTime(vals, kSecOIDX509V1ValidityNotAfter);
    std::string serialNumber = MacUtils::CFStringRefToStringUsingUTF8String((CFStringRef)CFDictionaryGetValue((CFDictionaryRef)CFDictionaryGetValue(vals, kSecOIDX509V1SerialNumber), kSecPropertyKeyValue));
    
    return boost::shared_ptr<X509CertificateMac>(new X509CertificateMac(host, cert_ref, issuerX500Principal, subjectX500Principal, version, validityNotBefore, validityNotAfter, serialNumber));
}


FB::JSAPIPtr X509CertificateMac::get_issuerX500Principal()
{
    return boost::shared_ptr<X500Principal>(new X500Principal(m_issuerX500Principal));
}

FB::FBDateString X509CertificateMac::get_notAfter()
{
    return m_validityNotAfter;
}

FB::FBDateString X509CertificateMac::get_notBefore()
{
    return m_validityNotBefore;
}


std::string X509CertificateMac::get_serialNumber()
{
    return m_serialNumber;
}


FB::JSAPIPtr X509CertificateMac::get_subjectX500Principal()
{
    return boost::shared_ptr<X500Principal>(new X500Principal(m_subjectX500Principal));
}


long X509CertificateMac::get_version()
{
    return m_version;
}


FB::VariantList X509CertificateMac::get_keyUsage()
{
    // TODO implement
    return FB::VariantList();
}

std::string X509CertificateMac::extractName(SecCertificateRef cert_ref)
{
    CFStringRef commonName = NULL;
    SecCertificateCopyCommonName(cert_ref, &commonName);
    std::string result = MacUtils::CFStringRefToStringUsingUTF8String(commonName);

    return result;
}

std::string X509CertificateMac::extractDateTime(CFDictionaryRef vals, CFTypeRef dateTimeRef)
{
    CFNumberRef validityNotBeforeRef = (CFNumberRef)CFDictionaryGetValue((CFDictionaryRef)CFDictionaryGetValue(vals, dateTimeRef), kSecPropertyKeyValue);
    CFAbsoluteTime validityNotBefore;
    CFNumberGetValue(validityNotBeforeRef, kCFNumberDoubleType, &validityNotBefore);
    
    static CFTimeZoneRef zoneSystem = CFTimeZoneCopySystem();
    CFGregorianDate validityNotBeforeGregorianDate = CFAbsoluteTimeGetGregorianDate(validityNotBefore, zoneSystem);
    
    char buffer [25];
    sprintf(buffer, "%u-%02u-%02uT%02u:%02u:%02.2f", validityNotBeforeGregorianDate.year, validityNotBeforeGregorianDate.month, validityNotBeforeGregorianDate.day, validityNotBeforeGregorianDate.hour, validityNotBeforeGregorianDate.minute, validityNotBeforeGregorianDate.second);
    
    return buffer;
}

X500Principal X509CertificateMac::convertToX500Principal(const FB::BrowserHostPtr& host, CFArrayRef x500PrincipalRef)
{
    std::wstringstream wss;
    
    CFIndex count = CFArrayGetCount(x500PrincipalRef);
    for (CFIndex idx = 0; idx < count; ++idx)
    {
        if (idx != 0)
        {
            wss << L", ";
        }
        CFDictionaryRef entry = (CFDictionaryRef)CFArrayGetValueAtIndex(x500PrincipalRef, idx);
        std::wstring oid = MacUtils::CFStringRefToWString((CFStringRef)CFDictionaryGetValue(entry, kSecPropertyKeyLabel));
        std::wstring value = MacUtils::CFStringRefToWString((CFStringRef)CFDictionaryGetValue(entry, kSecPropertyKeyValue));
        
        std::map<std::wstring, std::wstring>::iterator it = m_oid_to_str.find(oid);
        if (it != m_oid_to_str.end())
        {
            wss << it->second;
        }
        else
        {
            wss << oid;
        }
        wss << L"=" << value;
    }
    
    return X500Principal(host, wss.str());
}

std::map<std::wstring, std::wstring> X509CertificateMac::createOIDtoStringMapping()
{
    std::map<std::wstring, std::wstring> mapping;
    
    m_oid_to_str[L"2.5.4.3"] = L"CN";
    m_oid_to_str[L"2.5.4.7"] = L"L";
    m_oid_to_str[L"2.5.4.8"] = L"ST";
    m_oid_to_str[L"2.5.4.10"] = L"O";
    m_oid_to_str[L"2.5.4.11"] = L"OU";
    m_oid_to_str[L"2.5.4.6"] = L"C";
    m_oid_to_str[L"2.5.4.9"] = L"STREET";
    
    // Extra fields from RFC 2253
    m_oid_to_str[L"0.9.2342.19200300.100.1.25"] = L"DC";
    m_oid_to_str[L"0.9.2342.19200300.100.1.1"] = L"UID";
    
    //m_oid_to_str[L"2.5.4.5"] = L"SERIALNUMBER";
    
    return mapping;
}