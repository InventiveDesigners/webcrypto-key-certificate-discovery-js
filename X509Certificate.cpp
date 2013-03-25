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

X509Certificate::X509Certificate(const X509Certificate&other) : JSAPIAuto(other.m_description), m_host(other.m_host)
{
    initializeProperties();
}

X509Certificate& X509Certificate::operator=(const X509Certificate& other)
{
    m_host = other.m_host;
    
    initializeProperties();
    
    return *this;
}

void X509Certificate::initializeProperties()
{
    registerProperty("issuerX500Principal",  make_property(this, &X509Certificate::get_issuerX500Principal));
    
    // TODO register notAfter and notBefore (type is commented out)
    //registerProperty("notAfter",  make_property(this, &X509Certificate::get_notAfter));
    //registerProperty("notBefore",  make_property(this, &X509Certificate::get_notBefore));
    // registerProperty("publicKey",  make_property(this, &X509Certificate::get_publicKey));
    // registerProperty("privateKey",  make_property(this, &X509Certificate::get_privateKey));
    registerProperty("serialNumber",  make_property(this, &X509Certificate::get_serialNumber));
    registerProperty("subjectX500Principal",  make_property(this, &X509Certificate::get_subjectX500Principal));
    registerProperty("version",  make_property(this, &X509Certificate::get_version));
    registerProperty("keyUsage",  make_property(this, &X509Certificate::get_keyUsage)); // See rfc5280 for more information
    // registerProperty("extendedKeyUsage",  make_property(this, &X509Certificate::get_extendedKeyUsage)); // See rfc5280 for more information
}

