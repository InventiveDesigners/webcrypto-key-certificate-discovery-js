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
//  Key.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 29/03/13.
//
//

#ifndef __FireBreath__Key__
#define __FireBreath__Key__

#include <string>

#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "Algorithm.h"


class Key : public FB::JSAPIAuto
{
public:
    Key(const FB::BrowserHostPtr& host, std::string type, bool extractable, Algorithm algorithm, FB::VariantList keyUsage);
    virtual ~Key() {};
    
    Key(const Key& other);
    Key& operator=(const Key& other);
    
    std::string get_type();
    bool get_extractable();
    FB::JSAPIPtr get_algorithm();
    FB::VariantList get_keyUsage();

protected:
    FB::BrowserHostPtr m_host;
    
private:
    void initializeProperties();
    
private:
    std::string m_type;
    bool m_extractable;
    Algorithm m_algorithm;
    FB::VariantList m_keyUsage;
};

#endif /* defined(__FireBreath__Key__) */
