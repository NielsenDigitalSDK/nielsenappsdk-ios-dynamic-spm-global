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

@class NlsLogger;
@class NlsUrlParser;
@class NlsUtil;

@protocol NlsUrlParserDelegate <NSObject>

- (NSString*)urlParser:(NlsUrlParser*)parser valueForMissedKey:(NSString*)missedKey;

@end

@interface NlsUrlParser : NSObject

@property (nonatomic, readonly) NSArray *errors;

- (instancetype)initWithLogger:(NlsLogger *)logger;
- (instancetype)initWithLogger:(NlsLogger *)logger delegate:(id<NlsUrlParserDelegate>)delegate;

@property (nonatomic, strong) NSDictionary *dictionary;

- (void)addDictionary:(NSDictionary *)dictionary;
- (BOOL)setValueToParser:(id)value forKey:(NSString *)key;
- (NSString *)valueFromParserForKey:(NSString *)key;

- (NSString *)processIagData;

- (BOOL)calculateVariable:(long long)playheadPosition
               offsetName:(NSString *)offsetName;

- (NSString *)parse:(NSString *)urlToParse withResult:(BOOL *)pSuccess withKey:(NSString **)resultKey;
- (NSString *)parse:(NSString *)urlToParse withResult:(BOOL *)pSuccess;

@end
