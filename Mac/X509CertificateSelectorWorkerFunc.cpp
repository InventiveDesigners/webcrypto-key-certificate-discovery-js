#include <string>
#include <vector>
#include <Security/Security.h>

#include "MacUtils.h"
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
            
            int version = certType;
            
            CFStringRef commonName = NULL;
            SecCertificateCopyCommonName(cert_ref, &commonName);
            std::string name = MacUtils::CFStringRefToStringUsingUTF8String(commonName);
                        
            result.push_back(make_variant(boost::shared_ptr<X509Certificate>(new X509CertificateMac(selector->m_host, MacUtils::CFStringRefToStringUsingUTF8String(commonName)))));
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
