//
//  OVSConfig.h
//  OVSKit
//
//  Created by Xu Liu on 2017-08-27.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface OVSConfig : NSObject

///app key for this application
@property(nonatomic, strong) NSString * _Nullable applicationKey;

///this is the server url that we are going to send the API call for the base url
@property(nonatomic, strong) NSString * _Nullable serverURL;

+(OVSConfig * _Nonnull)sharedInstance;


///get current device iformation in Dictionary
-(NSDictionary * _Nonnull)getDeviceInfo;

///get the description of the current device for the app
-(NSString * _Nonnull)getDeviceInfoDescription;

/**
 @brief when app starts, we need to set up the app key for the OVSKit. all the following requests are based on the appKey. OVSKit is going to call this method to validate and register the app key.
 @discussion you can get the appKey from our developer.openvs.org website.
 @param appKey it is the unique key to identify your app. you can get it from developer.openvs.org website
 @param completion indicates the app key is valid or not from ovs server. it returns a BOOL value to indicate is valid or not
 */
-(void)registerAppKey:(NSString * _Nonnull)appKey onCompletion:(void(^_Nullable)(BOOL isValid, NSString * message, double expiredDate))completion;


/**
 @brief get the device identifier which is assigned by the OVSKit.
 @discussion if you delete the app and install the app again, the deviceIdentifier may change. if it is the first time you install the app, it will automatically generate the device identifier and return you the result.
 @return device identifier, which is unique for each device.
 */
-(NSString * _Nonnull)getDeviceIdentifier;


///return the current status of the app key. it is used to check the app key is valid or not
-(BOOL)getAppKeyValidationStatus;


///everytime when the app go to the background and comes to foreground. need to reload the Configuration.
-(void)reloadConfiguration;


///this function will returns the necessary request header each request needed
-(NSDictionary * _Nonnull)getUniformRequestHeader;

///get logo and version for the OVSKit.
-(NSString * _Nonnull)getOVSKitLogo;
@end
