//
//  MacUtils.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#include "MacUtils.h"


std::string MacUtils::CFStringRefToStringUsingUTF8String(CFStringRef aString) {
    
    if (aString == NULL) {
        return "";
    }
    
    CFIndex length = CFStringGetLength(aString);
    CFIndex maxSize =
    CFStringGetMaximumSizeForEncoding(length,
                                      kCFStringEncodingUTF8);
    char *buffer = (char *)malloc(maxSize);
    if (CFStringGetCString(aString, buffer, maxSize,
                           kCFStringEncodingUTF8)) {
        std::string result = std::string(buffer);
        free(buffer);
        return result;
    }
    return "";
}