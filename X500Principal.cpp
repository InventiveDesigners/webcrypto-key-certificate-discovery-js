//
//  X500Principal.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#include "X500Principal.h"

X500Principal::X500Principal(const FB::BrowserHostPtr& host, std::wstring name) : JSAPIAuto(std::string(name.begin(), name.end())), m_host(host), m_name(name)
{
    initializeProperties();
}

X500Principal::X500Principal(const X500Principal&other) : JSAPIAuto(std::string(other.m_name.begin(), other.m_name.end())),  m_host(other.m_host), m_name(other.m_name)
{
    initializeProperties();
}

X500Principal& X500Principal::operator=(const X500Principal& other)
{
    m_host = other.m_host;
    m_name = other.m_name;
    
    initializeProperties();
    
    return *this;
}

std::wstring X500Principal::get_name()
{
    return m_name;
}

void X500Principal::initializeProperties()
{
    registerProperty("name",  make_property(this, &X500Principal::get_name));
}