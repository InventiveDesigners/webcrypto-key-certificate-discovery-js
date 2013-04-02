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
