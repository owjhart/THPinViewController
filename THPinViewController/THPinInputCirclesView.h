//
//  THPinInputCirclesView.h
//  THPinViewControllerExample
//
//  Created by Thomas Heß on 20.4.14.
//  Copyright (c) 2014 Thomas Heß. All rights reserved.
//

@import UIKit;
#import "THPinViewControllerMacros.h"

typedef void (^THPinInputCirclesViewShakeCompletionBlock)(void);

@interface THPinInputCirclesView : UIView

@property (nonatomic, assign) NSUInteger pinLength;

- (nonnull instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(nonnull NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithPinLength:(NSUInteger)pinLength NS_DESIGNATED_INITIALIZER;

- (void)fillCircleAtPosition:(NSUInteger)position;
- (void)unfillCircleAtPosition:(NSUInteger)position;
- (void)unfillAllCircles;
- (void)shakeWithCompletion:(nonnull THPinInputCirclesViewShakeCompletionBlock)completion;

@end
