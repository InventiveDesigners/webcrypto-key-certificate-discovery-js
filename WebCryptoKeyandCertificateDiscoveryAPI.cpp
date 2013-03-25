/**********************************************************\

  Auto-generated WebCryptoKeyandCertificateDiscoveryAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "WebCryptoKeyandCertificateDiscoveryAPI.h"

#include "X509CertificateSelector.h"

FB::JSAPIPtr WebCryptoKeyandCertificateDiscoveryAPI::createX509CertificateSelector(FB::VariantMap selectorParams)
{
    return boost::shared_ptr<X509CertificateSelector>(new X509CertificateSelector(m_host));
}
