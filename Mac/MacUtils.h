//
//  MacUtils.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#ifndef __FireBreath__MacUtils__
#define __FireBreath__MacUtils__

#include <string>
#include <CoreFoundation/CoreFoundation.h>


class MacUtils
{
public:
    static std::string CFStringRefToStringUsingUTF8String(CFStringRef aString);
    static std::wstring CFStringRefToWString(CFStringRef aString);
};


#endif /* defined(__FireBreath__MacUtils__) */
