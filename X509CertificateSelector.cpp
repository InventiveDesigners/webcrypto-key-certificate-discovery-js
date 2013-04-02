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
