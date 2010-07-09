//
//  DBAdManager.m
//  Formulus
//
//  Created by Daniel Byon on 7/9/10.
//  Copyright 2010 Daniel Byon. All rights reserved.
//

#import "DBAdManager.h"

@interface UIDevice (iOS4)

+ (BOOL)isRunningiOS4;

@end

@implementation UIDevice (iOS4)

+ (BOOL)isRunningiOS4 {
	return [[UIDevice currentDevice] respondsToSelector:@selector(isMultitaskingSupported)];
}

@end


@implementation DBAdManager
@synthesize currentViewController;
@synthesize admobPublisherID;

#pragma mark -
#pragma mark AdMobDelegate Methods
- (NSString *)publisherIdForAd:(AdMobView *)adView {
	return self.admobPublisherID;
}

- (UIViewController *)currentViewControllerForAd:(AdMobView *)adView {
	return self.currentViewController;
}

#pragma mark -
#pragma mark NSObject Methods
- (id)initWithController:(UIViewController *)controller adMobPublisherID:(NSString *)publisherID {
	if (self = [super init]) {
		self.currentViewController = controller;
		self.admobPublisherID = publisherID;
	}
	return self;
}

- (UIView *)adForDisplay {
	if ([UIDevice isRunningiOS4]) {
		// Use iAd
		ADBannerView *iad = [[[ADBannerView alloc] initWithFrame:CGRectZero] autorelease];
		iad.currentContentSizeIdentifier = ADBannerContentSizeIdentifier320x50;
		return iad;
	} else {
		// Use AdMob
		return [AdMobView requestAdWithDelegate:self];;
	}
}

- (CGFloat)heightOfAd {
	if ([UIDevice isRunningiOS4]) {
		return 50.0f;
	} else {
		return 48.0f;
	}
}

- (void)dealloc {
	[currentViewController release], currentViewController = nil;
	[admobPublisherID release], admobPublisherID = nil;
	[super dealloc];
}

@end
