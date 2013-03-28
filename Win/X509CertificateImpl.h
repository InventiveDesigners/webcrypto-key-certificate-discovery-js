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
    virtual std::string get_serialNumber();
    virtual FB::JSAPIPtr get_subjectX500Principal();
    virtual long get_version();
    virtual FB::VariantList get_keyUsage(); // See rfc5280 for more information
};

#endif /* defined(__FireBreath__X509CertificateImpl__) */
