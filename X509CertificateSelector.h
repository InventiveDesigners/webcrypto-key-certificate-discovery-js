//
//  X509CertificateSelector.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 22/03/13.
//
//

#ifndef __FireBreath__X509CertificateSelector__
#define __FireBreath__X509CertificateSelector__

#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "KeyOperation.h"

class X509CertificateSelector : public KeyOperation
{
    friend void X509CertificateSelectorWorkerFunc(X509CertificateSelector * selector);
public:
    X509CertificateSelector(const FB::BrowserHostPtr& host);
    virtual ~X509CertificateSelector() {};
    
    void execute();

private:
    X509CertificateSelector(const X509CertificateSelector& other) : KeyOperation(other) { initializeMethods(); };
    
    
private:
    void initializeMethods();
};

#endif /* defined(__FireBreath__X509CertificateSelector__) */
