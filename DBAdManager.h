//
//  DBAdManager.h
//  Formulus
//
//  Created by Daniel Byon on 7/9/10.
//  Copyright 2010 Daniel Byon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <iAd/iAd.h>
#import "AdMobView.h"
#import "AdMobDelegateProtocol.h"

@interface DBAdManager : NSObject <AdMobDelegate> {
	UIViewController *currentViewController;
	NSString *admobPublisherID;
}
@property (nonatomic, retain) UIViewController *currentViewController;
@property (nonatomic, retain) NSString *admobPublisherID;

// Designated Initializer
- (id)initWithController:(UIViewController *)controller adMobPublisherID:(NSString *)publisherID;

// This method returns the ad
- (UIView *)adForDisplay;

// This method returns the height of the ad (e.g. setting tableView:heightForFooterInSection:)
- (CGFloat)heightOfAd;

@end
