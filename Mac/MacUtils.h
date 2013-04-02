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
