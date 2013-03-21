#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for Web Crypto Key and Certificate Discovery
#
#\**********************************************************/

set(PLUGIN_NAME "WebCryptoKeyandCertificateDiscovery")
set(PLUGIN_PREFIX "WCKCD")
set(COMPANY_NAME "InventiveDesigners")

# ActiveX constants:
set(FBTYPELIB_NAME WebCryptoKeyandCertificateDiscoveryLib)
set(FBTYPELIB_DESC "WebCryptoKeyandCertificateDiscovery 1.0 Type Library")
set(IFBControl_DESC "WebCryptoKeyandCertificateDiscovery Control Interface")
set(FBControl_DESC "WebCryptoKeyandCertificateDiscovery Control Class")
set(IFBComJavascriptObject_DESC "WebCryptoKeyandCertificateDiscovery IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "WebCryptoKeyandCertificateDiscovery ComJavascriptObject Class")
set(IFBComEventSource_DESC "WebCryptoKeyandCertificateDiscovery IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID ef6f6862-7a76-5c3d-a3df-94582ae821ec)
set(IFBControl_GUID 101c7129-35cb-5f03-9578-aa21b3141db7)
set(FBControl_GUID 5c3f77ce-6f14-56f3-ab90-81db091b5ab3)
set(IFBComJavascriptObject_GUID 7d985eef-36cb-5eda-bebb-652a434a6a1b)
set(FBComJavascriptObject_GUID 970c4c99-e68e-5041-b0d4-66bf53425382)
set(IFBComEventSource_GUID 48ce3cd8-8b34-565a-9aef-0dada3bee81c)
if ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID 779c6b78-b4f8-5a73-929a-f8c14b31bb2d)
else ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID 2f0941f6-e103-5ac7-adee-807aa105f215)
endif ( FB_PLATFORM_ARCH_32 )

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "InventiveDesigners.WebCryptoKeyandCertificateDiscovery")
set(MOZILLA_PLUGINID "inventivedesigners.com/WebCryptoKeyandCertificateDiscovery")

# strings
set(FBSTRING_CompanyName "Inventive Designers")
set(FBSTRING_PluginDescription "This plug-in will add support for the Web Crypto Key and Certificate Discovery API to your browser.")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2013 Inventive Designers")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "Web Crypto Key and Certificate Discovery")
set(FBSTRING_FileExtents "")
if ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "Web Crypto Key and Certificate Discovery")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "Web Crypto Key and Certificate Discovery_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )
set(FBSTRING_MIMEType "application/x-webcryptokeyandcertificatediscovery")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

#set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 1)
set(FBMAC_USE_COCOA 1)
set(FBMAC_USE_COREGRAPHICS 1)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
