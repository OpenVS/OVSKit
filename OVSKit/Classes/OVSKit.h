//
//  OVSKit.h
//  OVSKit
//
//  Created by Xu Liu on 2017-05-15.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import <UIKit/UIKit.h>
#import "OVSDataManager.h"
#import "OVSHelper.h"

// This is used to indicate the downloading progress when we try to download the app installer
#define OVS_NOTIFICATION_DOWNLOAD_PROGRESS @"updateDownloadWebAppProgressIfNeeded"

// This is used to listen the global alert information, which can be decied to pop up
#define OVS_NOTIFICATION_NOTIFY_USER_MESSAGE @"globalMessageToUserIfNeeded"

// This is used to notify the listener the upgrade process is done
#define OVS_NOTIFICATION_NOTIFY_UPGRADE_IS_DONE @"WebAppUpgradeIsDone"

// This is used to let the app know, the device web app loads process is done. need to dismiss launch page
#define OVS_NOTIFICATION_NOTIFY_WEBAPP_IS_READY @"WebAppIsReady"

@protocol OVSKitDelegate
@optional
-(void)finishInitializeWebView;
@end

@interface OVSKit : NSObject
@property(nonatomic, strong) id<OVSKitDelegate> delegate;
+(OVSKit *)sharedInstance;

// 1. At the very beginning, we need to set up the default web configuration, so that we can use some registered javascript function, if we know what kind of function we want to load, we can write our own web configuration
-(WKWebViewConfiguration *)defaultWebConfiguration;

// 2. When we use OVSKit, we need to set up the AppKey first in the AppDidFinishLaunch
-(void)setAppKey:(NSString *)appKey onCompletion:(void(^)(BOOL isValid, NSString * message, double expiredDate))completion;

// 3. After that, in the ViewController, we need to register the WebView to OVSKit. so that we can finish initialization
-(BOOL)registerWebView:(WKWebView *)webView parentViewController:(UIViewController *)parentViewController;

// 4. Assign the WebApp package to the OVSKit
-(void)loadApp:(NSString * _Nonnull)appName;
@end
