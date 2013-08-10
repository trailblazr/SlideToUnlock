//
//  SlideToUnlockViewController.h
//  SlideToUnlock
//
//  Created by Alex Nichol on 9/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ANSlider.h"

@interface SlideToUnlockViewController : UIViewController<ANSliderDelegate> {

    IBOutlet UILabel *statusLabel;
    IBOutlet UIButton *buttonReset;
    ANSlider *slider;
    CGPoint sliderOriginalCenter;
}

@property( nonatomic, retain ) UILabel *statusLabel;
@property( nonatomic, retain ) ANSlider *slider;
@property( nonatomic, retain ) UIButton *buttonReset;
@property( nonatomic, assign ) CGPoint sliderOriginalCenter;

- (IBAction) actionReset:(id)sender;

@end
