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
//  X509CertificateImpl.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#include "X509CertificateImpl.h"

X509CertificateImpl::X509CertificateImpl(const FB::BrowserHostPtr& host, std::string name) : X509Certificate(host, name)
{
}

X509CertificateImpl::X509CertificateImpl(const X509CertificateImpl& other) : X509Certificate(other)
{
}

X509CertificateImpl& X509CertificateImpl::operator=(const X509CertificateImpl& other)
{
    X509Certificate::operator=(other);
    
    return *this;
}


FB::JSAPIPtr X509CertificateImpl::get_issuerX500Principal()
{
    // TODO implement
    return boost::shared_ptr<X500Principal>(new X500Principal(m_host, L""));
}

FB::FBDateString X509CertificateImpl::get_notAfter()
{
    // TODO implement
    return FB::FBDateString();
}

FB::FBDateString X509CertificateImpl::get_notBefore()
{
    // TODO implement
    return FB::FBDateString();
}


std::string X509CertificateImpl::get_serialNumber()
{
    // TODO implement
    return "0";
}


FB::JSAPIPtr X509CertificateImpl::get_subjectX500Principal()
{
    // TODO implement
    return boost::shared_ptr<X500Principal>(new X500Principal(m_host, L""));
}


long X509CertificateImpl::get_version()
{
    // TODO implement
    return 3;
}


FB::VariantList X509CertificateImpl::get_keyUsage()
{
    // TODO implement
    return FB::VariantList();
}
