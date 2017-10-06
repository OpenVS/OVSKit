//
//  OVSAppDelegate.m
//  OVSKit
//
//  Created by kkliuxu@gmail.com on 09/03/2017.
//  Copyright (c) 2017 kkliuxu@gmail.com. All rights reserved.
//

#import "OVSAppDelegate.h"
#include "OVSHelper.h"
#include "OVSKit.h"
#include "OVSSecurity.h"

@implementation OVSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	NSString * appName = [[OVSHelper sharedInstance] getAppName];
	NSLog(@"appName:%@", appName);
	
	[[OVSDataManager sharedInstance] setGeneralKeyPair:@"$LUId&49jQVg]i(swJQGuP)$D7%tpx$0" iv:@"a6q%l&H%t&fQbd*X"];
	[OVSKit setAppKey:@"SomeAppKey"];
	[OVSKit showDeviceInfo];
	NSString * encryptedText = [OVSSecurity generalKeyForSafeStringFromOriginal:@"Hello World, It is working!"];
	NSLog(@"Encrypted Text:%@", encryptedText);
	NSString * decryptedText = [OVSSecurity generalKeyForOriginalStringFromSafeString:encryptedText];
	NSLog(@"Original Text:%@", decryptedText);
    NSData * data = [[OVSHelper sharedInstance] dataFromJSONArray: @[@{@"A":@"B"}, @{@"C":@(2)}]];
    NSArray * array = [[OVSHelper sharedInstance] arrayFromJSONData:data];
    NSLog(@"Array from JSON data:%@", array);
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
