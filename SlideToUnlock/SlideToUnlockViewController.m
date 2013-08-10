//
//  SlideToUnlockViewController.m
//  SlideToUnlock
//
//  Created by Alex Nichol on 9/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "SlideToUnlockViewController.h"

@implementation SlideToUnlockViewController

@synthesize statusLabel;
@synthesize slider;
@synthesize buttonReset;
@synthesize sliderOriginalCenter;

- (void) dealloc;
{
    slider.delegate = nil;
    self.slider = nil;
    self.statusLabel = nil;
    self.buttonReset = nil;
    [super dealloc];
}

- (void)didReceiveMemoryWarning;
{
    [super didReceiveMemoryWarning];
}

#pragma mark - view handling

- (void)viewDidLoad;
{
    [super viewDidLoad];
	self.slider = [[[ANSlider alloc] initWithFrame:CGRectMake(0, self.view.frame.size.height - 95, 320, 95)] autorelease];
    slider.delegate = self;
	[slider startAnimating:self];
	[self.view addSubview:[slider autorelease]];
    self.sliderOriginalCenter = slider.center;
    buttonReset.hidden = YES;
}

- (NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortrait;
}

#pragma mark - user actions

- (IBAction) actionReset:(id)sender;
{
    [slider reset];
    [UIView animateWithDuration:0.5 animations:^{
        slider.center = sliderOriginalCenter;
    } completion:^(BOOL finished) {
        buttonReset.hidden = YES;
    }];
}

#pragma mark - ANSliderDelegate

- (void) sliderUnlocked:(ANSlider*)sliderView;
{
    self.statusLabel.text = @"UNLOCKED.";
    [UIView animateWithDuration:0.5 animations:^{
        sliderView.center = CGPointMake(sliderView.center.x, sliderView.center.y+sliderView.bounds.size.height);
    } completion:^(BOOL finished) {
        buttonReset.hidden = NO;
    }];
}

- (void) sliderMoved:(ANSlider*)sliderView;
{
    self.statusLabel.text = @"MOVING...";
}

- (void) sliderStillLocked:(ANSlider*)sliderView;
{
    self.statusLabel.text = @"LOCKED.";
}

@end
