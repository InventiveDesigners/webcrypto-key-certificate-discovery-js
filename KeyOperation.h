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
//  KeyOperation.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 22/03/13.
//
//

#ifndef __FireBreath__KeyOperation__
#define __FireBreath__KeyOperation__

#include "JSAPIAuto.h"
#include "BrowserHost.h"

class KeyOperation : public FB::JSAPIAuto
{
public:
    KeyOperation(const FB::BrowserHostPtr& host);
    
    virtual ~KeyOperation() {};
            
    void set_result(FB::variant result);
    FB::variant get_result();
    
    
protected:
    FB::BrowserHostPtr m_host;

private:
    FB::variant m_result;
    
    void initializeProperties();
};

#endif /* defined(__FireBreath__KeyOperation__) */
