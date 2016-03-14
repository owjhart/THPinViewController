//
//  THPinViewController.h
//  THPinViewController
//
//  Created by Thomas Heß on 11.4.14.
//  Copyright (c) 2014 Thomas Heß. All rights reserved.
//

@import UIKit;
#import "THPinViewControllerMacros.h"

@class THPinViewController;

// when using translucentBackground assign this tag to the view that should be blurred
static const NSInteger THPinViewControllerContentViewTag = 14742;

@protocol THPinViewControllerDelegate <NSObject>

@required
- (NSUInteger)pinLengthForPinViewController:(nonnull THPinViewController *)pinViewController;
- (BOOL)pinViewController:(nonnull THPinViewController *)pinViewController isPinValid:(nonnull NSString *)pin;
- (BOOL)userCanRetryInPinViewController:(nonnull THPinViewController *)pinViewController;

@optional
- (void)incorrectPinEnteredInPinViewController:(nonnull THPinViewController *)pinViewController;

- (void)pinViewControllerWillDismissAfterPinEntryWasSuccessful:(nonnull THPinViewController *)pinViewController;

/**
 The pinViewController is automatically dismissed unless the delegate implements this method returning \c NO.
 One reason to prevent dismissing would be to use this view controller to let the user set up the PIN by entering the number, then confirming it.
   1. After the user has entered the first number, return \c NO to keep the controller visible,
   2. change the prompt in /c -pinViewControllerWillReset:,
   3. finally return \c YES after the user has successfully entered the new PIN a second time.
 */
- (BOOL)pinViewControllerShouldDismissAfterPinEntryWasSuccessful:(nonnull THPinViewController *)pinViewController;
- (void)pinViewControllerDidDismissAfterPinEntryWasSuccessful:(nonnull THPinViewController *)pinViewController;

- (void)pinViewControllerWillDismissAfterPinEntryWasUnsuccessful:(nonnull THPinViewController *)pinViewController;
- (void)pinViewControllerDidDismissAfterPinEntryWasUnsuccessful:(nonnull THPinViewController *)pinViewController;

- (void)pinViewControllerWillDismissAfterPinEntryWasCancelled:(nonnull THPinViewController *)pinViewController;
- (void)pinViewControllerDidDismissAfterPinEntryWasCancelled:(nonnull THPinViewController *)pinViewController;

/**
 Called when the delegate returned \c NO for \c pinViewControllerShouldDismissAfterPinEntryWasSuccessful:
 This gives the delegate a chance to update the promptTitle and/or any colors while the pin view is refreshed.
 */
- (void)pinViewControllerWillReset:(nonnull THPinViewController *)pinViewController;

@end

@interface THPinViewController : UIViewController

@property (nonatomic, nullable, weak) id<THPinViewControllerDelegate> delegate;
@property (nullable, nonatomic, strong) UIColor *backgroundColor; // is only used if translucentBackground == NO
@property (nonatomic, assign) BOOL translucentBackground;
@property (nullable, nonatomic, copy) NSString *promptTitle;
@property (nullable, nonatomic, strong) UIColor *promptColor;
@property (nonatomic, assign) BOOL hideLetters; // hides the letters on the number buttons
@property (nonatomic, assign) BOOL disableCancel; // hides the cancel button

- (nonnull instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(nonnull NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithDelegate:(nullable id<THPinViewControllerDelegate>)delegate NS_DESIGNATED_INITIALIZER;

@end
