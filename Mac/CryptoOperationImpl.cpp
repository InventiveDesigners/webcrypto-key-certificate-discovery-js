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
//  CryptoOperationImpl.cpp
//  FireBreath
//
//  Created by Nick Van den Bleeken on 03/04/13.
//
//

#include "CryptoOperationImpl.h"
#include "KeyImpl.h"

#include <boost/thread.hpp>
#include <Security/SecTransform.h> 
#include <Security/SecSignVerifyTransform.h> 

CryptoOperationImpl::~CryptoOperationImpl()
{
    if (m_signingTransform)
    {
        CFRelease(m_signingTransform);
        m_signingTransform = NULL;
    }
}


void CryptoOperationImpl::processImpl(const char *buffer, unsigned long size)
{
    initialize();
    
    CFErrorRef error = NULL;
    CFDataRef dataRef = CFDataCreate(kCFAllocatorDefault, (UInt8*)buffer, size);
    
    //TODO doesn't seems to work, it looks like only the first kSecTransformInputAttributeName is used.
    
    SecTransformSetAttribute(m_signingTransform,
                             kSecTransformInputAttributeName, dataRef, &error);
    
    if (NULL != error)
    {
        CFRelease(m_signingTransform);
        m_signingTransform = NULL;
        callOnAbort();
    }
}

// DEBUG
static CFStringRef SecCopyHexStringFromData(CFDataRef data)
{
    CFIndex ix, length;
	const UInt8 *bytes;
    CFMutableStringRef string;
    
	if (data) {
		length = CFDataGetLength(data);
		bytes = CFDataGetBytePtr(data);
	} else {
		length = 0;
		bytes = NULL;
	}
	string = CFStringCreateMutable(kCFAllocatorDefault, length * 2);
    for (ix = 0; ix < length; ++ix)
		CFStringAppendFormat(string, NULL, CFSTR("%02X"), bytes[ix]);
    
    return string;
}


void CryptoOperationImpl::finishImpl()
{
    CFErrorRef error = NULL;
    CFDataRef signature = (CFDataRef)SecTransformExecute(m_signingTransform, &error);
    
    if (NULL != error)
    {
        callOnAbort();
        return;
    }
    
    CFIndex length = CFDataGetLength(signature);
    const UInt8 *signatureBytes = CFDataGetBytePtr(signature);
    
    std::vector<unsigned char> result((unsigned char*)signatureBytes, ((unsigned char*)signatureBytes) + length);
    
    set_result(result);
    
    CFRelease(signature);
    CFRelease(m_signingTransform);
    m_signingTransform = NULL;
    
    if (NULL != error)
    {
        callOnAbort();
        return;
    }
    
    callOnComplete();
}


SecKeyRef CryptoOperationImpl::getKeyRef()
{
    return ((KeyImpl&)*get_key()).getKey();
}

void CryptoOperationImpl::initialize()
{
    if (m_signingTransform)
    {
        // We have already initialized the signing transform
        return;
    }
    
    m_signingTransform = SecSignTransformCreate(getKeyRef(), NULL);
    SecTransformSetAttribute(m_signingTransform, kSecInputIsDigest, kCFBooleanTrue, NULL);
    SecTransformSetAttribute(m_signingTransform, kSecDigestTypeAttribute, kSecDigestSHA1, NULL);
}

