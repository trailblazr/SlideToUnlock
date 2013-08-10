//
//  ANSlider.h
//  SlideToUnlock
//
//  Created by Alex Nichol on 9/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ANImageBitmapRep.h"
#import "EaseOutSmoothAnimation.h"

@protocol ANSliderDelegate;

@interface ANSlider : UIView {
    
    id<ANSliderDelegate>delegate;
    
	// Text
	NSString * drawText;
	UIImage * darkImage;
	UIImage * brightImage;
	CGImageRef particleImage;
	CGPoint particlePosition;
	// Slider elements
	UIImage * backgroundImage;
	UIImage * sliderImage;
	CGPoint sliderCoordinates;
	// Animations
	NSTimer * particleTimer;
	NSDate * lastSlideDate;
	// Touch events
	CGFloat startTouch;
	CGFloat startSliderX;
	BOOL isDragging;
	// Sliding back
	BOOL isSlidingBack; // If set, no touch events are valid.
	EaseOutSmoothAnimation * easeOut;
}

@property( nonatomic, assign ) id<ANSliderDelegate>delegate;

- (void)startAnimating:(id)sender;
- (void)stopAnimating:(id)sender;
- (void)setDrawText:(NSString *)someText;
- (NSString *)drawText;
- (void)reset;

@end

@protocol ANSliderDelegate <NSObject>

- (void) sliderUnlocked:(ANSlider*)sliderView;

@optional

- (void) sliderMoved:(ANSlider*)sliderView;
- (void) sliderStillLocked:(ANSlider*)sliderView;

@end
