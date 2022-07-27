/**
 * App SDK Application
 *
 * Copyright (C) 2016, The Nielsen Company (US) LLC. All Rights Reserved.
 *
 * Software contains the Confidential Information of Nielsen and is subject to your relevant agreements with Nielsen.
 *
 * remarks:
 *
 */

#import <Foundation/Foundation.h>
#import "NielsenAppApi.h"

#define kKeychainValueUpdatedNotification @"KeychainValueUpdated"

#define kKeychainAppDisable @"nol_appdisable"
#define kKeychainAppDisableSentKey @"sdk_appdisablesent"
#define kKeychainUserOptOut @"nol_useroptout"
#define kKeychainUserOptUrlUserChoice @"nol_useroptUrlUserChoice"
#define kKeychainUserOptUrlIDFA @"nol_useroptUrlIDFA"
#define kKeychainErrorUrl @"nol_errorURL"
#define kKeychainEncryptDevID @"nol_encryptDevId"
#define kKeychainTsvFlag @"nol_tsvFlag"
#define kKeychainMaxLength @"nol_maxLength"
#define kKeychainNuid @"nol_nuid"

#if TARGET_OS_TV
#define kKeychainOfflinePingsLimit @"nol_tvOSOfflinePingsLimit"
#else
#define kKeychainOfflinePingsLimit @"nol_offlinePingsLimit"
#endif

#define kKeychainSessionSizeLimit @"nol_sessionSizeLimit"
#define kKeychainLaunchPingLimit @"nol_launchPingLimit"
#define kKeychainLaunchProcessorMasterAppIdKey @"sdk_launchProcessorMasterAppId"


@class NlsKeychainItemWrapper;
@class NlsErrorReporter;

@interface NlsKeychainStorage : NSObject

@property (nonatomic, assign) BOOL appDisable;
@property (nonatomic, assign) BOOL appDisableSent;
@property (nonatomic, assign) BOOL userOptOut;
@property (nonatomic, strong) NSString *userOptOutURLUserChoice;
@property (nonatomic, strong) NSString *userOptOutURLIDFA;
@property (nonatomic, strong) NSString *errorURL;
@property (nonatomic, assign) BOOL encryptDevId;
@property (nonatomic, strong) NSString *tsvFlag;
@property (nonatomic, strong) NSString *maxMsgLength;
@property (nonatomic, strong) NSString *pendingPingsLimit;
@property (nonatomic, strong) NSString *sessionSizeLimit;
@property (nonatomic, strong) NSString *launchPingLimit;
@property (nonatomic, strong) NSString *launchProcessorMasterAppId;
@property(nonatomic, readonly) BOOL isMissingEntitlement;

- (instancetype)initWithErrorReporter:(NlsErrorReporter *)reporter;

@end
