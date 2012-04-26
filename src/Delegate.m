//
//  Delegate.m
//
//  Created by Sander ter Braak on 24-04-12.
//  Copyright (c) 2012 Haute Technique. All rights reserved.
//
/*
#import "Delegate.h"

#define NotifierNotification				@"OpenFrameworks Notification"
#define NotifierHumanReadableDescription    NSLocalizedString(@"OpenFrameworks Notification", "")

@implementation Delegate

- (void)setup {
    Class GAB = NSClassFromString(@"GrowlApplicationBridge");
    if([GAB respondsToSelector:@selector(setGrowlDelegate:)]){
		[GAB performSelector:@selector(setGrowlDelegate:) withObject:self];

    }
}

- (NSDictionary *) registrationDictionaryForGrowl {
	NSDictionary *notificationsWithDescriptions = [NSDictionary dictionaryWithObjectsAndKeys:
												   NotifierHumanReadableDescription, NotifierNotification,			
												   nil];
	NSArray *allNotifications = [notificationsWithDescriptions allKeys];
	NSMutableArray *defaultNotifications = [allNotifications mutableCopy];
    NSDictionary *regDict = [NSDictionary dictionaryWithObjectsAndKeys:
							 @"MultiGrowlExample", GROWL_APP_NAME,
							 allNotifications, GROWL_NOTIFICATIONS_ALL,
							 defaultNotifications,	GROWL_NOTIFICATIONS_DEFAULT,
							 notificationsWithDescriptions,	GROWL_NOTIFICATIONS_HUMAN_READABLE_NAMES,
							 nil];
	[defaultNotifications release];
	return regDict;
}


- (void) sendWithTitle:(NSString * )title description:(NSString *) desciption sticky:(BOOL) sticky {
	Class GAB = NSClassFromString(@"GrowlApplicationBridge");
	if([GAB respondsToSelector:@selector(notifyWithTitle:description:notificationName:iconData:priority:isSticky:clickContext:identifier:)])
		[GAB notifyWithTitle:title
                 description:desciption
            notificationName:(NSString *)NotifierNotification
                    iconData:nil//(NSData *)firewireLogo()
                    priority:0
                    isSticky:sticky
                clickContext:nil
                  identifier:title];
	
}

@end
*/