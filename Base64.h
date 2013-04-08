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
//  Base64.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 05/04/13.
//

#ifndef __FireBreath__Base64__
#define __FireBreath__Base64__

#include <string>

class Base64 {
public:
    static char *decode(std::string base64, int *resultLength);
    static std::string encode(unsigned char *buffer, int length);
    
private:
    static char m_encodingTable[];
    static char *m_decodingTable;
    static int m_modTable[];
    
    static void build_decoding_table();
    

};

#endif /* defined(__FireBreath__Base64__) */
