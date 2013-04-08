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
//  Key.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 29/03/13.
//
//

#include "Key.h"

Key::Key(const FB::BrowserHostPtr& host, std::string type, bool extractable, Algorithm algorithm, FB::VariantList keyUsage) : JSAPIAuto("Key"), m_host(host), m_type(type), m_extractable(extractable), m_algorithm(algorithm), m_keyUsage(keyUsage)
{
    initializeProperties();
}

Key::Key(const Key&other) : JSAPIAuto("Key"),  m_host(other.m_host), m_type(other.m_type), m_extractable(other.m_extractable), m_algorithm(other.m_algorithm), m_keyUsage(other.m_keyUsage)
{
    initializeProperties();
}

Key& Key::operator=(const Key& other)
{
    m_host = other.m_host;
    m_type = other.m_type;
    m_extractable = other.m_extractable;
    m_algorithm = other.m_algorithm;
    m_keyUsage = other.m_keyUsage;
    
    initializeProperties();
    
    return *this;
}

std::string Key::get_type()
{
    return m_type;
}

bool Key::get_extractable()
{
    return m_extractable;
}

FB::JSAPIPtr Key::get_algorithm()
{
    return boost::shared_ptr<Algorithm>(new Algorithm(m_algorithm));
}

FB::VariantList Key::get_keyUsage()
{
    return m_keyUsage;
}

void Key::initializeProperties()
{
    registerProperty("type",  make_property(this, &Key::get_type));
    registerProperty("extractable",  make_property(this, &Key::get_extractable));
    registerProperty("algorithm",  make_property(this, &Key::get_algorithm));
    registerProperty("keyUsage",  make_property(this, &Key::get_keyUsage));
}
