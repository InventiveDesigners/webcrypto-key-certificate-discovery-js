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

class X509CertificateMac: public X509Certificate
{
public:
    X509CertificateMac(const FB::BrowserHostPtr& host, std::string name);
    virtual ~X509CertificateMac() {};
    
    X509CertificateMac(const X509CertificateMac& other);
    X509CertificateMac& operator=(const X509CertificateMac& other);
    
    virtual FB::JSAPIPtr get_issuerX500Principal();
    virtual FB::FBDateString get_notAfter();
    virtual FB::FBDateString get_notBefore();
    virtual long get_serialNumber();
    virtual FB::JSAPIPtr get_subjectX500Principal();
    virtual long get_version();
    virtual FB::VariantList get_keyUsage(); // See rfc5280 for more information
};

#endif /* defined(__FireBreath__X509CertificateMac__) */
