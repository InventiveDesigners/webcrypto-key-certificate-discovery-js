//
//  X509CertificateSelector.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 22/03/13.
//
//

#include "X509CertificateSelector.h"

#include <boost/thread.hpp>
#include <string>

void X509CertificateSelectorWorkerFunc(X509CertificateSelector * selector);

X509CertificateSelector::X509CertificateSelector(const FB::BrowserHostPtr& host) : KeyOperation(host)
{
    initializeMethods();
}

void X509CertificateSelector::initializeMethods()
{
    registerMethod("execute",      make_method(this, &X509CertificateSelector::execute));
}


void X509CertificateSelector::execute()
{
    boost::thread workerThread(X509CertificateSelectorWorkerFunc, this);
}
