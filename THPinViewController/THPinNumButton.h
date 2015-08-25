//
//  THPinNumButton.h
//  THPinViewController
//
//  Created by Thomas Heß on 14.4.14.
//  Copyright (c) 2014 Thomas Heß. All rights reserved.
//

@import UIKit;
#import "THPinViewControllerMacros.h"

@interface THPinNumButton : UIButton

@property (nonatomic, readonly, assign) NSUInteger number;
@property (nullable, nonatomic, readonly, copy) NSString *letters;

- (nonnull instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(nonnull NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNumber:(NSUInteger)number letters:(nullable NSString *)letters NS_DESIGNATED_INITIALIZER;

+ (CGFloat)diameter;

@end
