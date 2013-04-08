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
//  Algorithm.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 29/03/13.
//
//

#ifndef __FireBreath__Algorithm__
#define __FireBreath__Algorithm__

#include <string>

#include "JSAPIAuto.h"
#include "BrowserHost.h"


class Algorithm : public FB::JSAPIAuto
{
public:
    Algorithm(const FB::BrowserHostPtr& host, std::string name, FB::VariantMap params);
    virtual ~Algorithm() {};
    
    Algorithm(const Algorithm& other);
    Algorithm& operator=(const Algorithm& other);
    
    std::string get_name();
    FB::VariantMap get_params();
    
private:
    FB::BrowserHostPtr m_host;
    std::string m_name;
    FB::VariantMap m_params;
    
private:
    void initializeProperties();
};

#endif /* defined(__FireBreath__Algorithm__) */
