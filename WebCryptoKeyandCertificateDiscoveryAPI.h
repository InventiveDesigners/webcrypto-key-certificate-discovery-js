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

