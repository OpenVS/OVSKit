//
//  OVSThemeManager.h
//  OVSKit
//
//  Created by Xu Liu on 2017-06-08.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OVSLog.h"
#import "OVSHelper.h"

@interface OVSThemeManager : NSObject

///this function will update the button's background color, font size, and so on based on the theme configuration
+(void)configButton:(UIButton *_Nonnull)button withThemeCode:(NSString *_Nonnull)themeCode;

///this function will update the label's background color, font size, and so on based on the theme configuration
+(void)configLabel:(UILabel *_Nonnull)label withThemeCode:(NSString *_Nonnull)themeCode;

///this function will update the view's background color, font size, and so on based on the theme configuration
+(void)configView:(UIView *_Nonnull)view withThemeCode:(NSString *_Nonnull)themeCode;

///this function will update the UIImageView's background color, border color and so on based on the theme configuration
+(void)configImage:(UIImageView *_Nonnull)imageView useImage:(NSString *_Nonnull)imageName withThemeCode:(NSString *_Nonnull)themeCode;

///this function will update the UIPageControl's background color, tint color and so on based on the theme configuration
+(void)configPageControl:(UIPageControl *_Nonnull)pageControl withThemeCode:(NSString *_Nonnull)themeCode;

///this function will update the UITextField background color, tint color and so on based on the theme configuration
+(void)configTextField:(UITextField *_Nonnull)textField withThemeCode:(NSString *_Nonnull)themeCode;

///config the element's shadow
+(void)configViewShadow:(UIView *_Nonnull)view withThemeCode:(NSString *_Nonnull)themeCode;

///get the background layer for the view controller
+(void)addGradientLayerBackgroundToView:(UIView *_Nonnull)view;


///this will return the color based on the theme configuration file, if the value is empty, it will use the transparent background.
+(UIColor *_Nonnull)getElementBackgroundColor:(NSString *_Nonnull)themeCode;
+(UIColor *_Nonnull)getElementTintColor:(NSString *_Nonnull)themeCode;

+(UIColor *_Nonnull)getElementFontColor:(NSString *_Nonnull)themeCode;
+(float)getElementFontSize:(NSString *_Nonnull)themeCode;
+(NSString *_Nonnull)getElementFontFamily:(NSString *_Nonnull)themeCode;

///this will return the color based on the theme configuration file, if the value is empty, it will use the transparent background.
+(UIColor * _Nonnull)getElementBorderColor:(NSString *_Nonnull)themeCode;
+(float)getElementBorderSize:(NSString *_Nonnull)themeCode;


///set up general configuration key and value, by calling this function, it will look for the whole code
+(UIColor * _Nonnull)getElementColorByCode:(NSString * _Nonnull)themeCode withDefaultColor:(UIColor * _Nonnull)color;
+(float)getElementFloatByCode:(NSString * _Nonnull)themeCode withDefaultFloat:(float)value;
+(NSString * _Nonnull)getElementStringByCode:(NSString * _Nonnull)themeCode withDefaultString:(NSString * _Nonnull)string;
+(BOOL)getElementBoolByCode:(NSString * _Nonnull)themeCode withDefaultBool:(BOOL)value;



///this is related to UIImage
+(BOOL)isEnabledImageViewTemplate:(NSString *_Nonnull)themeCode;

@end
