//
//  X500Principal.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#ifndef __FireBreath__X500Principal__
#define __FireBreath__X500Principal__

#include "JSAPIAuto.h"
#include "BrowserHost.h"

class X500Principal : public FB::JSAPIAuto
{
public:
    X500Principal(const FB::BrowserHostPtr& host, std::wstring name);
    virtual ~X500Principal() {};
    
    X500Principal(const X500Principal& other);
    X500Principal& operator=(const X500Principal& other);
    
    std::wstring get_name();
    
protected:
    FB::BrowserHostPtr m_host;
    std::wstring m_name;
    
private:
    void initializeProperties();
};

#endif /* defined(__FireBreath__X500Principal__) */
