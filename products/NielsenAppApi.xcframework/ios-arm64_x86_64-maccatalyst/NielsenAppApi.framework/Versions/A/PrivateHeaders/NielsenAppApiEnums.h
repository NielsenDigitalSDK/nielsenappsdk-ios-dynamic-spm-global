/**
 * App SDK Application
 *
 * Copyright (C) 2026, The Nielsen Company (US) LLC. All Rights Reserved.
 *
 * Software contains the Confidential Information of Nielsen and is subject to your relevant agreements with Nielsen.
 *
 * remarks:
 *
 */

#ifndef NielsenAppApiEnums_h
#define NielsenAppApiEnums_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, NielsenProductType) {
    ID3RawProduct = 0,
    DprPatternProduct,
    DprId3PatternProduct,
    MtvrPatternProduct,
    MtvrSubminutePatternProduct,
    OCRProduct,
    LegacyProduct,
    DrmPatternProduct,
    DcrVideoPatternProduct,
    DcrStaticProduct,
    VriProduct,
    OtherProduct
};

typedef NS_ENUM(NSUInteger, NlsSessionStopType) {
    NlsSessionStopTypeOnPlay = 0,
    NlsSessionStopTypeOnAdInterruption,
    NlsSessionStopTypeOnAssetIdChange,
    NlsSessionStopTypeOnStop
};

typedef NS_ENUM(unsigned int, NielsenApiType) {
    NielsenApiTypeTrackEvent,
    NielsenApiTypeLegacy
};


#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
static const int kNlsIPhoneOSVersionMinRequired = __IPHONE_OS_VERSION_MIN_REQUIRED;
#endif

#ifdef __VISION_OS_VERSION_MIN_REQUIRED
static const int kNlsVisionOSVersionMinRequired = __VISION_OS_VERSION_MIN_REQUIRED;
#endif

#endif /* NielsenAppApiEnums_h */

