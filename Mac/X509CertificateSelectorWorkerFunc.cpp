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

#include <string>
#include <vector>
#include <Security/Security.h>

#include "../X509CertificateSelector.h"
#include "X509CertificateMac.h"

void X509CertificateSelectorWorkerFunc(X509CertificateSelector * selector)
{
    CFArrayRef   certs_ref     = NULL;
    const void *keys[] =   { kSecClass, kSecReturnRef, kSecMatchLimit };
    const void *values[] = { kSecClassCertificate, kCFBooleanTrue, kSecMatchLimitAll };
    CFDictionaryRef dict = CFDictionaryCreate(NULL, keys, values, sizeof(keys) / sizeof(*keys), NULL, NULL);
    OSStatus status = SecItemCopyMatching(dict, (CFTypeRef*) &certs_ref);
    
    if (status == noErr)
    {
        FB::VariantList result;
        for (CFIndex i = 0; i < CFArrayGetCount(certs_ref); ++i) {
            SecCertificateRef cert_ref = (SecCertificateRef)CFArrayGetValueAtIndex(certs_ref, i);
            
            CSSM_CERT_TYPE certType = NULL;
            SecCertificateGetType(cert_ref, &certType);
            
            if (certType != CSSM_CERT_X_509v1 && certType != CSSM_CERT_X_509v2 && certType != CSSM_CERT_X_509v3)
            {
                continue;
            }
                        
            result.push_back(make_variant(X509CertificateMac::createX509CertificateMac(selector->m_host, cert_ref)));
        }
        
        selector->set_result(result);
        selector->callOnComplete();
    }
    else
    {
        selector->callOnError();
    }
    
    if (dict)
        CFRelease(dict);
}
