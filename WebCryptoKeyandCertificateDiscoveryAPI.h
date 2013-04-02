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

/**********************************************************\

  Auto-generated WebCryptoKeyandCertificateDiscoveryAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "WebCryptoKeyandCertificateDiscovery.h"

#ifndef H_WebCryptoKeyandCertificateDiscoveryAPI
#define H_WebCryptoKeyandCertificateDiscoveryAPI

class WebCryptoKeyandCertificateDiscoveryAPI : public FB::JSAPIAuto
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @fn WebCryptoKeyandCertificateDiscoveryAPI::WebCryptoKeyandCertificateDiscoveryAPI(const WebCryptoKeyandCertificateDiscoveryPtr& plugin, const FB::BrowserHostPtr host)
    ///
    /// @brief  Constructor for your JSAPI object.
    ///         You should register your methods, properties, and events
    ///         that should be accessible to Javascript from here.
    ///
    /// @see FB::JSAPIAuto::registerMethod
    /// @see FB::JSAPIAuto::registerProperty
    /// @see FB::JSAPIAuto::registerEvent
    ////////////////////////////////////////////////////////////////////////////
    WebCryptoKeyandCertificateDiscoveryAPI(const WebCryptoKeyandCertificateDiscoveryPtr& plugin, const FB::BrowserHostPtr& host) :
        m_plugin(plugin), m_host(host)
    {
        registerMethod("createX509CertificateSelector",      make_method(this, &WebCryptoKeyandCertificateDiscoveryAPI::createX509CertificateSelector));
       
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @fn WebCryptoKeyandCertificateDiscoveryAPI::~WebCryptoKeyandCertificateDiscoveryAPI()
    ///
    /// @brief  Destructor.  Remember that this object will not be released until
    ///         the browser is done with it; this will almost definitely be after
    ///         the plugin is released.
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~WebCryptoKeyandCertificateDiscoveryAPI() {};

    WebCryptoKeyandCertificateDiscoveryPtr getPlugin();

    FB::JSAPIPtr createX509CertificateSelector(FB::VariantMap selectorParams);

private:
    WebCryptoKeyandCertificateDiscoveryWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
};

#endif // H_WebCryptoKeyandCertificateDiscoveryAPI

