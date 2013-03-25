//
//  KeyOperation.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 22/03/13.
//
//

#include "KeyOperation.h"

// if (m_callback) // if not NULL
//   m_callback->InvokeAsync("", FB::variant_list_of(a)("Param2")(3));

KeyOperation::KeyOperation(const FB::BrowserHostPtr& host): m_host(host)
{
    initializeProperties();
}


KeyOperation::KeyOperation(const KeyOperation& other) : m_host(other.m_host)
{
    initializeProperties();
    
    m_oncomplete = other.m_oncomplete;
    m_onerror = other.m_onerror;
    m_result = other.m_result;
}

KeyOperation& KeyOperation::operator=(const KeyOperation& other)
{
    m_host = other.m_host;
    m_oncomplete = other.m_oncomplete;
    m_onerror = other.m_onerror;
    m_result = other.m_result;
    
    return *this;
}

void KeyOperation::initializeProperties()
{
    registerProperty("onerror",  make_property(this, &KeyOperation::get_onerror, &KeyOperation::set_onerror));
    registerProperty("oncomplete",  make_property(this, &KeyOperation::get_oncomplete, &KeyOperation::set_oncomplete));
    registerProperty("result",  make_property(this, &KeyOperation::get_result));
}

void KeyOperation::set_onerror(const FB::JSObjectPtr& onerror) {
    m_onerror = onerror;
}

FB::JSObjectPtr KeyOperation::get_onerror() {
    return m_onerror;
}

void KeyOperation::set_oncomplete(const FB::JSObjectPtr& oncomplete) {
    m_oncomplete = oncomplete;
}

FB::JSObjectPtr KeyOperation::get_oncomplete() {
    return m_oncomplete;
}

FB::variant KeyOperation::get_result() {
    return m_result;
}

void KeyOperation::set_result(FB::variant result) {
    m_result = result;
}

void KeyOperation::callOnComplete() const {
    if (m_oncomplete)
        m_oncomplete->InvokeAsync("", FB::variant_list_of());
}


void KeyOperation::callOnError() const {
    if (m_onerror)
        m_onerror->InvokeAsync("", FB::variant_list_of());
}