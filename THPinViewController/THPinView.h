//
//  THPinView.h
//  THPinViewControllerExample
//
//  Created by Thomas Heß on 21.4.14.
//  Copyright (c) 2014 Thomas Heß. All rights reserved.
//

@import UIKit;
#import "THPinViewControllerMacros.h"

@class THPinView;

@protocol THPinViewDelegate <NSObject>

@required
- (NSUInteger)pinLengthForPinView:(nonnull THPinView *)pinView;
- (BOOL)pinView:(nonnull THPinView *)pinView isPinValid:(nonnull NSString *)pin;
- (void)cancelButtonTappedInPinView:(nonnull THPinView *)pinView;
- (void)correctPinWasEnteredInPinView:(nonnull THPinView *)pinView;
- (void)incorrectPinWasEnteredInPinView:(nonnull THPinView *)pinView;

@end

@interface THPinView : UIView

@property (nonatomic, weak) id<THPinViewDelegate> delegate;
@property (nullable, nonatomic, copy) NSString *promptTitle;
@property (nullable, nonatomic, strong) UIColor *promptColor;
@property (nonatomic, assign) BOOL hideLetters;
@property (nonatomic, assign) BOOL disableCancel;

- (nonnull instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(nonnull NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithDelegate:(nullable id<THPinViewDelegate>)delegate NS_DESIGNATED_INITIALIZER;

- (void)resetInput;

@end
