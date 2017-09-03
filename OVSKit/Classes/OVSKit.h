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

///define asynchronized error callback
typedef void(^ErrorCallback)(int statusCode, NSString * errorMessage, NSError * error);

///define asynchronized success callback
typedef void(^SuccessCallback)(int statusCode, NSString * message, NSMutableDictionary * result);
/**
 @brief when app starts, we need to set up the app key for the OVSKit. all the following requests are based on the appKey.
 @discussion you can get the appKey from our developer.openvs.org website.
 @param appKey it is the unique key to identify your app. you can get it from developer.openvs.org website
 */
+(void)setAppKey:(NSString *)appKey;

/**
 @brief this is used to set up a server url which will override the default openvs url
 @param serverURL your own server url. the format should like "https://your.server.domain"
 */
+(void)setServerURL:(NSString *)serverURL;


/**
 @brief this function will print out the device ralted information for user. just in debug mode. if it is release mode, this won't be printed
 */
+(void)showDeviceInfo;

/**
 @brief when app starts, we need to set up the app key for the OVSKit. all the following requests are based on the appKey.
 @discussion you can get the appKey from our developer.openvs.org website.
 @param appKey it is the unique key to identify your app. you can get it from developer.openvs.org website
 @param completion indicates the app key is valid or not from ovs server. it returns a BOOL value to indicate is valid or not
 */
+(void)setAppKey:(NSString *)appKey onCompletion:(void(^)(BOOL isValid))completion;

/**
 @brief call this function will make the device send a network request to our server with device information. remote server may based on the request device information to return a certain number of configuration to config this app.
 @discussion this function let develop track device and make statistics. It will bring device's
 */
+(void)registerDevice;


/**
 @brief if you want to have the push notification feature enabled by the app. you need to go to capabilities tab in your project solution tab. and turn on the Notification section. after that, call this function whenever you think is the good place to pop up the Push Notification permission dialog.
 @discussion this function let OVSKit to register the push notification to App. and then, after a while, if the registration is successfully. we will receive a push notification token back. and then, call prepareNotification for the app
 */
+(void)registerPushNotification;

/**
 @brief when application's did register for remote notification comes back. this function needs to be called
 @discussion it is a callback function in app delegate. this function is used with registerPushNotificaiton function
 @param data the returned data from didRegisterForRemoteNotification
 */
+(void)preparePushNotification:(NSData *)data;


/**
 @brief this function is used to pass the username and password, then login the system
 @discussion if you don't assign the app key at the beginning of the app. this function won't work. This function uses two callback functions to pass the parameters, They are success and error callback to indicate the login is successful or not.
 */
+(void)loginWithUsername:(NSString *)username password:(NSString *)password onSuccess:(SuccessCallback)success onError:(ErrorCallback)error;

@end
