//
//  DBAdManager.h
//  Formulus
//
//  Created by Daniel Byon on 7/9/10.
//  Copyright 2010 Daniel Byon. All rights reserved.
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
