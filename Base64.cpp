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
//  Base64.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 05/04/13.
//

#include <boost/cstdint.hpp>

#include "Base64.h"

char Base64::m_encodingTable[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'};
char* Base64::m_decodingTable = NULL;
int Base64::m_modTable[] = {0, 2, 1};



std::string Base64::encode(unsigned char *buffer, int inputLength)
{
    int resultLength = 4 * ((inputLength + 2) / 3);
    
    char *encoded_data = new char[resultLength];
    if (encoded_data == NULL) return NULL;
    
    for (int i = 0, j = 0; i < inputLength;) {
        
        uint32_t octet_a = i < inputLength ? buffer[i++] : 0;
        uint32_t octet_b = i < inputLength ? buffer[i++] : 0;
        uint32_t octet_c = i < inputLength ? buffer[i++] : 0;
        
        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;
        
        encoded_data[j++] = m_encodingTable[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = m_encodingTable[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = m_encodingTable[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = m_encodingTable[(triple >> 0 * 6) & 0x3F];
    }
    
    for (int i = 0; i < m_modTable[inputLength % 3]; i++)
        encoded_data[resultLength - 1 - i] = '=';
    
    std::string result= std::string(encoded_data, resultLength);
    delete encoded_data;
    
    return result;
}



char *Base64::decode(std::string base64, int *resultLength)
{
    
    if (m_decodingTable == NULL) build_decoding_table();
    
    int inputLength = base64.length();
    if (inputLength % 4 != 0) return NULL;
    
    *resultLength = inputLength / 4 * 3;
    if (base64[inputLength - 1] == '=') (*resultLength)--;
    if (base64[inputLength - 2] == '=') (*resultLength)--;
    
    char *decodedData = new char[*resultLength];
    if (decodedData == NULL) return NULL;
    
    for (int i = 0, j = 0; i < inputLength;) {
        
        uint32_t sextet_a = base64[i] == '=' ? 0 & i++ : m_decodingTable[(int)base64[i++]&0xFF];
        uint32_t sextet_b = base64[i] == '=' ? 0 & i++ : m_decodingTable[(int)base64[i++]&0xFF];
        uint32_t sextet_c = base64[i] == '=' ? 0 & i++ : m_decodingTable[(int)base64[i++]&0xFF];
        uint32_t sextet_d = base64[i] == '=' ? 0 & i++ : m_decodingTable[(int)base64[i++]&0xFF];
        
        uint32_t triple = (sextet_a << 3 * 6)
        + (sextet_b << 2 * 6)
        + (sextet_c << 1 * 6)
        + (sextet_d << 0 * 6);
        
        if (j < *resultLength) decodedData[j++] = (triple >> 2 * 8) & 0xFF;
        if (j < *resultLength) decodedData[j++] = (triple >> 1 * 8) & 0xFF;
        if (j < *resultLength) decodedData[j++] = (triple >> 0 * 8) & 0xFF;
    }
    
    return decodedData;
}


void Base64::build_decoding_table() {
    
    m_decodingTable = new char[256];
    
    for (int i = 0; i < 256; i++)
        m_decodingTable[(int)m_encodingTable[i]] = i;
}
