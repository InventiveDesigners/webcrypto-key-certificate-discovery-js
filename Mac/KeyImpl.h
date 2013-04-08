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
//  KeyImpl.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 03/04/13.
//
//

#ifndef __FireBreath__KeyImpl__
#define __FireBreath__KeyImpl__

#include "../Key.h"

#include <Security/SecBase.h>

class KeyImpl : public Key
{
public:
    KeyImpl(const FB::BrowserHostPtr& host, std::string type, bool extractable, Algorithm algorithm, FB::VariantList keyUsage, const boost::shared_ptr<SecKeyRef>& key) : Key(host, type, extractable, algorithm, keyUsage), m_key(key) {}
    virtual ~KeyImpl() {}
    
    KeyImpl(const KeyImpl& other) : Key(other), m_key(other.m_key) {}
    KeyImpl& operator=(const KeyImpl& other) { Key::operator=(other); m_key = other.m_key; return *this;}
    
    SecKeyRef getKey() { return *m_key;}
    
private:
    boost::shared_ptr<SecKeyRef> m_key;
};


#endif /* defined(__FireBreath__KeyImpl__) */
