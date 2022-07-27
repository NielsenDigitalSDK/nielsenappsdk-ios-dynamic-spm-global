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

#import <UIKit/UIKit.h>

@class NlsApiWorker;
@class NlsUrlParser;
@class NlsLogger;
@class NlsSwUtil;

@interface NlsUtil : NSObject

// Swift refactored
+ (BOOL)isNullOrEmpty:(NSString *)string;
+ (BOOL)isNumeric:(NSString *)string;
+ (BOOL)isProductionBuild;


// Not refactored
+ (BOOL)isString:(NSString *)string1 caseInsensitiveEqualTo:(NSString *)string2;
+ (BOOL)isAppIdValid:(NSString *)appId;
+ (NSNumber *)numberFromString:(NSString *)string;
+ (NSString *)randomDigitStringWithLength:(int)len;
+ (BOOL)matchesWord:(NSString*)word inString:(NSString *)inputString;
+ (NSString *)firstMatchForPattern:(NSString *)pattern inString:(NSString *)string;
+ (id)JSONObjectFromString:(NSString *)string;
+ (NSString *)stringFromJSONObject:(id)object;
+ (NSString *)stringforDictionary:(id)jsonDict;
+ (BOOL)isArrayNullOrEmpty:(NSArray *)array;
+ (BOOL)isArray:(NSArray *)array consistsOfObjectsOnlyOfTheClass:(Class)aClass;
+ (NSString *)nuidUserAgentFormatted:(NSString *)nuid;
+ (BOOL)boolValueForString:(NSString *)string withDefault:(BOOL)defaultValue;

+ (NSString *)uriEncodedString:(NSString *)string;
+ (NSString *)md5EncodedString:(NSString *)string;
+ (NSString *)xorEncodedString:(NSString *)string withKey:(NSString *)key;
+ (NSString *)sessionUAID;

+ (NSDictionary *)checkFilters:(NSArray *)filterArray forDict:(NSDictionary *)origDict withCidNull:(NSString *)cidNull useImmed:(BOOL)bUseRslt;
+ (NSString *)preparePingUrlWithUrlParser:(NlsUrlParser *)urlParser forDictionary:(NSDictionary *)dict processorId:(NSInteger)processorId worker:(NlsApiWorker *)worker arrivalTime:(NSTimeInterval)arrivalTime withResult:(BOOL *)pSuccess;
+ (NSString *)incrementRetryCounterInThePing:(NSString *)ping withReasonCode:(NSInteger)reasonCode;
+ (NSString *)incrementRetryCounterInJson:(NSString *)data withReasonCode:(NSInteger)reasonCode;
+ (NSString *)retryCounterValueFromThePing:(NSString *)ping;
+ (NSString *)clientApplicationVersion;
+ (NSString *)appIdDirectoryPath:(NSString *)appId withErrorLogger:(NlsLogger *)logger;
+ (NSString *)appFilePathWithName:(NSString *)fileName;
+ (BOOL)isFreeDiskspaceAvailableWithErrorLogger:(NlsLogger *)logger;

+ (NSString *)formattedDate:(NSDate *)date;
+ (NSString *)createdDate;

+ (id)clearItem:(id)item;
+ (id)clearItem:(id)item lowercaseDictValues:(BOOL)lowercaseValues;

+ (NSDictionary *)dictionaryWithStringForNumbersForDict:(NSDictionary *)dict;
+ (NSDictionary *)JSONRepresantableDictionaryForDictionary:(NSDictionary *)dictionary;

+ (BOOL)caseInsensitiveExistsObject:(id)object inArray:(NSArray *)array;

+ (NSString *)sfcodeWithClientSupplied:(NSString *)clientSfcode
                          configSfcode:(NSString *)configSfcode
                         defaultSfcode:(NSString *)defaultSfcode
                           debugSfcode:(NSString *)debugSfcode;
+ (NSString *)integrationTypeSuffixFromAppInfoDict:(NSDictionary *)appDict;

+ (BOOL)isObjectTypeValid:(id)inputObject withErrorLogger:(NlsLogger *)logger;
+ (NSDictionary *)dictionaryFromJSONString:(NSString *)jsonStr withErrorLogger:(NlsLogger *)logger;
+ (NSDictionary *)dictionaryFromInputObject:(id)inputObject withErrorLogger:(NlsLogger *)logger;
+ (NSDictionary *)dictionaryWithStringValuesOnly:(NSDictionary *)dict;
+ (NSString *)httpMethodWithRequestMethod:(NSString *)method prefMethod:(NSString *)prefMethod;

+ (void)validateSpecialCharsForValuesInDict:(NSDictionary *)dict withCmsMap:(NSDictionary *)map errorLogger:(NlsLogger *)logger;
+ (NSString *)generatePlayerIdUID;

+ (BOOL)isValidSenderForNotification:(NSNotification *)note;

@end
