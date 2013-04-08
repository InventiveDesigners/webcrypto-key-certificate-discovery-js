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
//  CryptoOperationImpl.h
//  FireBreath
//
//  Created by Nick Van den Bleeken on 03/04/13.
//
//

#ifndef __FireBreath__CryptoOperationImpl__
#define __FireBreath__CryptoOperationImpl__

#include "../CryptoOperation.h"
#include <Security/Security.h>

class CryptoOperationImpl : public CryptoOperation
{
public:
    CryptoOperationImpl(const FB::BrowserHostPtr& host, const boost::shared_ptr<Key>& key, const boost::shared_ptr<Algorithm>& algorithm) : CryptoOperation(host, key, algorithm), m_signingTransform(NULL) { }
    
    virtual ~CryptoOperationImpl();
        
    
    
protected:
    void processImpl(const char *buffer, unsigned long size);
    void finishImpl();
    
private:
    
    SecKeyRef getKeyRef();
    void initialize();
    
private:
    SecTransformRef m_signingTransform;
};

#endif /* defined(__FireBreath__CryptoOperationImpl__) */
