//
//  OVSSecurity.h
//  OVSKit
//
//  Created by Xu Liu on 2017-08-26.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//
// This class is used to handle all the possible encryption/decryption, zip/unzip data and string.
// as well as some security tasks.
#import <Foundation/Foundation.h>

@interface OVSSecurity : NSObject
+(OVSSecurity * _Nonnull)sharedInstance;

/**
 @brief convert the original string to safe string via general key
 @param original original text which need to be taken care for safty purpose
 @return return processed safe text from the original text
 */
+(NSString * _Nonnull)generalKeyForSafeStringFromOriginal:(NSString * _Nonnull)original;

/**
 @brief convert the safe string to original string via general key
 @param safeString string which generated by the same function like toSafeString.
 @return return original text
 */
+(NSString * _Nonnull)generalKeyForOriginalStringFromSafeString:(NSString * _Nonnull)safeString;

/**
 @brief convert the original string to safe string.
 @param original original text which need to be taken care for safty purpose
 @return return processed safe text from the original text
 */
+(NSString * _Nonnull)toSafeString:(NSString * _Nonnull)original;

/**
 @brief convert the safe string to original string.
 @param safeString string which generated by the same function like toSafeString.
 @return return original text
 */
+(NSString * _Nonnull)toOriginalString:(NSString * _Nonnull)safeString;

/**
 @brief convert the original data to safe data.
 @param original original data which need to be taken care for safty purpose
 @return processed safe data from the original data
 */
+(NSData * _Nonnull)toSafeData:(NSData * _Nonnull)original;


/**
 @brief convert the safe data to original data.
 @param safeData data which generated by the same function like toSafeData.
 @return return original data
 */
+(NSData * _Nonnull)toOriginalData:(NSData * _Nonnull)safeData;

/**
 @brief convert the original data to safe data by general key.
 @param original original data which need to be taken care for safty purpose
 @return processed safe data from the original data
 */
+(NSData * _Nonnull)toSafeDataByGeneralKey:(NSData * _Nonnull)original;


/**
 @brief convert the safe data to original data by general key.
 @param safeData data which generated by the same function like toSafeData.
 @return return original data
 */
+(NSData * _Nonnull)toOriginalDataByGeneralKey:(NSData * _Nonnull)safeData;



/// get general key for data safe transmission
+(NSString * _Nonnull)getOpenVSKitGeneralKey;

/// get general iv for data safe transmission
+(NSString * _Nonnull)getOpenVSKitGeneralIV;

/// get ovs kit version for security purpose
+(float)getOpenVSKitVersion;
@end