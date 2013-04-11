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
    CFArrayRef   identities_ref     = NULL;
    const void *keys[] =   { kSecClass, kSecReturnRef, kSecMatchLimit };
    const void *values[] = { kSecClassIdentity, kCFBooleanTrue, kSecMatchLimitAll }; // TODO we should list all certificates, but I can't find how to go back from a certificate to a private key
    CFDictionaryRef dict = CFDictionaryCreate(NULL, keys, values, sizeof(keys) / sizeof(*keys), NULL, NULL);
    OSStatus status = SecItemCopyMatching(dict, (CFTypeRef*) &identities_ref);
    
    if (status == noErr)
    {
        FB::VariantList result;
        for (CFIndex i = 0; i < CFArrayGetCount(identities_ref); ++i) {
            SecIdentityRef identity_ref = (SecIdentityRef)CFArrayGetValueAtIndex(identities_ref, i);
            
            SecCertificateRef cert_ref;
            SecIdentityCopyCertificate(identity_ref, &cert_ref);
            
            SecKeyRef privateKeyRef;
            SecIdentityCopyPrivateKey(identity_ref, &privateKeyRef);
            
            CSSM_CERT_TYPE certType = NULL;
            SecCertificateGetType(cert_ref, &certType);
            
            if (certType != CSSM_CERT_X_509v1 && certType != CSSM_CERT_X_509v2 && certType != CSSM_CERT_X_509v3)
            {
                continue;
            }
                        
            result.push_back(make_variant(X509CertificateMac::createX509CertificateMac(selector->m_host, cert_ref, privateKeyRef)));
        }
        
        selector->set_result(result);
        selector->FireJSEvent("oncomplete", FB::VariantMap(), FB::variant_list_of());
    }
    else
    {
        selector->FireJSEvent("onerror", FB::VariantMap(), FB::variant_list_of());
    }
    
    if (dict)
        CFRelease(dict);
}
