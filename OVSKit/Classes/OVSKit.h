//
//  OVSKit.h
//  OVSKit
//
//  Created by Xu Liu on 2017-05-15.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OVSDataManager.h"
#import "OVSHelper.h"

@interface OVSKit : NSObject

///shared instance for this ovs kit.
+(OVSKit *)sharedInstance;

///this function return the version of the OVSKit
+(NSString *)version;

///define asynchronized error callback
typedef void(^ErrorCallback)(int statusCode, NSString * errorMessage, NSError * error);

///define asynchronized success callback
typedef void(^SuccessCallback)(int statusCode, NSString * message, NSMutableDictionary * result);

/**
 @brief this function will print out the device ralted information for user. just in debug mode. if it is release mode, this won't be printed
 */
+(void)showDeviceInfo;

/**
 @brief when app starts, we need to set up the app key for the OVSKit. all the following requests are based on the appKey.
 @discussion you can get the appKey from our developer.openvs.org website.
 @param appKey it is the unique key to identify your app. you can get it from developer.openvs.org website
 @param completion indicates the app key is valid or not from ovs server. it returns a BOOL value to indicate is valid or not, Message is its description, expiredDate indicates when it will be invalid
 */
+(void)setAppKey:(NSString *)appKey onCompletion:(void(^)(BOOL isValid, NSString * message, double expiredDate))completion;

@end
