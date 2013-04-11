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
//  KeyOperation.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 22/03/13.
//
//

#include "KeyOperation.h"
#include "JSEvent.h"

// if (m_callback) // if not NULL
//   m_callback->InvokeAsync("", FB::variant_list_of(a)("Param2")(3));

KeyOperation::KeyOperation(const FB::BrowserHostPtr& host): m_host(host)
{
    initializeProperties();
}


void KeyOperation::initializeProperties()
{
    registerProperty("result",  make_property(this, &KeyOperation::get_result));
    
    registerEvent("oncomplete");
    registerEvent("onerror");
}

FB::variant KeyOperation::get_result() {
    return m_result;
}

void KeyOperation::set_result(FB::variant result) {
    m_result = result;
}
