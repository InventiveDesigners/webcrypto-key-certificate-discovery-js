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
