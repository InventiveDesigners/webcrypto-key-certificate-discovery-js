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

#include <string>
#include <vector>

#include <stdio.h>
#include <windows.h>
#include <Wincrypt.h>

#include "../X509CertificateSelector.h"
#include "X509CertificateImpl.h"

void X509CertificateSelectorWorkerFunc(X509CertificateSelector * selector)
{
	HCERTSTORE hCertStore = CertOpenStore(CERT_STORE_PROV_SYSTEM, 0, NULL, CERT_SYSTEM_STORE_CURRENT_USER, L"MY");

	if(!hCertStore)
	{
		selector->callOnError();
	}

	PCCERT_CONTEXT   pCertContext=NULL;
	wchar_t pszNameString[128];
	FB::VariantList result;
	while(pCertContext= CertEnumCertificatesInStore(hCertStore, pCertContext))
	{
		CertGetNameString(pCertContext, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, NULL, pszNameString, 128);
		std::wstring description = std::wstring((wchar_t*)&pszNameString);
	    result.push_back(FB::make_variant(boost::shared_ptr<X509Certificate>(new X509CertificateImpl(selector->m_host, std::string(description.begin(), description.end())))));
	}

    selector->set_result(result);
    selector->callOnComplete();
}
