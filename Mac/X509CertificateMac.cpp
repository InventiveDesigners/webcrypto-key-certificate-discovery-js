//
//  X509CertificateMac.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#include "X509CertificateMac.h"

X509CertificateMac::X509CertificateMac(const FB::BrowserHostPtr& host, std::string name) : X509Certificate(host, name)
{
}

X509CertificateMac::X509CertificateMac(const X509CertificateMac& other) : X509Certificate(other)
{
}

X509CertificateMac& X509CertificateMac::operator=(const X509CertificateMac& other)
{
    X509Certificate::operator=(other);
    
    return *this;
}


FB::JSAPIPtr X509CertificateMac::get_issuerX500Principal()
{
    // TODO implement
    return boost::shared_ptr<X500Principal>(new X500Principal(m_host, L""));
}

FB::FBDateString X509CertificateMac::get_notAfter()
{
    // TODO implement
    return FB::FBDateString();
}

FB::FBDateString X509CertificateMac::get_notBefore()
{
    // TODO implement
    return FB::FBDateString();
}


long X509CertificateMac::get_serialNumber()
{
    // TODO implement
    return 0;
}


FB::JSAPIPtr X509CertificateMac::get_subjectX500Principal()
{
    // TODO implement
    return boost::shared_ptr<X500Principal>(new X500Principal(m_host, L""));
}


long X509CertificateMac::get_version()
{
    // TODO implement
    return 3;
}


FB::VariantList X509CertificateMac::get_keyUsage()
{
    // TODO implement
    return FB::VariantList();
}
