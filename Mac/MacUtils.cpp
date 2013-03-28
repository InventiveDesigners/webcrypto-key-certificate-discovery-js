//
//  MacUtils.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 25/03/13.
//
//

#include "MacUtils.h"


std::string MacUtils::CFStringRefToStringUsingUTF8String(CFStringRef aString)
{    
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

std::wstring MacUtils::CFStringRefToWString(CFStringRef aString)
{
    if (aString == NULL) {
        return L"";
    }
    
    if (!aString)
        return false;
    CFDataRef cfData = CFStringCreateExternalRepresentation(kCFAllocatorDefault,
                                                            aString, kCFStringEncodingUTF32, 0);
    CFRelease(aString);
    if (!cfData)
        return false;
    int out_byte_len = CFDataGetLength(cfData);
    out_byte_len -= sizeof(wchar_t); // don't count the 32 bit BOM char at start
    int out_len = out_byte_len / sizeof(wchar_t);
    wchar_t *tmp = new wchar_t[out_len + 1];
    // start after the BOM, hence sizeof(wchar_t)
    CFDataGetBytes(cfData, CFRangeMake(sizeof(wchar_t), out_byte_len),
                   (UInt8*)tmp);
    CFRelease(cfData);
    tmp[out_len] = 0;
    std::wstring result = tmp;
    delete[] tmp;
    
    return result;
}