/**
* App SDK Application
*
* Copyright (C) 2020, The Nielsen Company (US) LLC. All Rights Reserved.
*
* Software contains the Confidential Information of Nielsen and is subject to your relevant agreements with Nielsen.
*
* remarks:
* New enhanced SDK JS Handler API
*/

#import <Foundation/Foundation.h>
#if !TARGET_OS_TV
#import <WebKit/WebKit.h>
#endif

@interface NielsenAppSDKJSHandler : NSObject
#if !TARGET_OS_TV
    /**
    Handler for WKScriptMessage
    */
    <WKScriptMessageHandler>
#endif

/**
Initializes the ID3Meter metering framework.
@param apiType - NSString object that defines api type processing by meter instance. Must be: @"trackEvent" for Track Event ; any other string or nil for ggPM.
@returns returns (id) pointer to object of a Meter object; nil if error occurred.
*/
- (nullable instancetype)initWithApiType:(nullable NSString *)apiType;

/**
Handler for React Native JS message
@param jsEmitter - RCTEventEmitter object that calls this API to pass message to JS Handler.
@param message - NSDictionary object that includes all the parameters required for reporting player updates to the SDK. Check documentation for proper key naming and values.
*/
- (void)jsEventEmitter:(nullable id)jsEmitter didReceiveScriptMessage:(nullable id)message;

@end
