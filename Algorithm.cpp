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
//  Algorithm.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 29/03/13.
//
//

#include "Algorithm.h"

Algorithm::Algorithm(const FB::BrowserHostPtr& host, std::string name, FB::VariantMap params) : JSAPIAuto(name), m_host(host), m_name(name), m_params(params)
{
    initializeProperties();
}

Algorithm::Algorithm(const Algorithm&other) : JSAPIAuto(std::string(other.m_name.begin(), other.m_name.end())),  m_host(other.m_host), m_name(other.m_name), m_params(other.m_params)
{
    initializeProperties();
}

Algorithm& Algorithm::operator=(const Algorithm& other)
{
    m_host = other.m_host;
    m_name = other.m_name;
    m_params = other.m_params;
    
    initializeProperties();
    
    return *this;
}

std::string Algorithm::get_name()
{
    return m_name;
}

FB::VariantMap Algorithm::get_params()
{
    return m_params;
}
void Algorithm::initializeProperties()
{
    registerProperty("name",  make_property(this, &Algorithm::get_name));
    registerProperty("params",  make_property(this, &Algorithm::get_params));
}
