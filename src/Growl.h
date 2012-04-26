//
//  Delegate.h
//
//  Created by Sander ter Braak on 24-04-12.
//  Copyright (c) 2012 Haute Technique. All rights reserved.
//
#import <Cocoa/Cocoa.h>
#import <Growl/Growl.h>

@interface Growl : NSObject <GrowlApplicationBridgeDelegate> {
    
    NSString * _name;
    ofxGrowl * _proxy;
}

- (void) setupWithName:(NSString *) name
              andProxy:(ofxGrowl *) proxy;
- (void) sendWithTitle:(NSString * )title description:(NSString *) desciption sticky:(BOOL) sticky icon:(NSString *) icon priority:(int)prio event:(NSString *) event;

@end

#define NotifierNotification				@"OpenFrameworks Notification"
#define NotifierHumanReadableDescription    NSLocalizedString(@"OpenFrameworks Notification", "")

@implementation Growl

- (void)setupWithName:(NSString *) name
             andProxy:(ofxGrowl *) proxy {
    _name = name;
    _proxy = proxy;
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
							 _name, GROWL_APP_NAME,
							 allNotifications, GROWL_NOTIFICATIONS_ALL,
							 defaultNotifications,	GROWL_NOTIFICATIONS_DEFAULT,
							 notificationsWithDescriptions,	GROWL_NOTIFICATIONS_HUMAN_READABLE_NAMES,
							 nil];
	[defaultNotifications release];
	return regDict;
}

- (void) growlNotificationWasClicked: (id) clickContext {
    string event = string([clickContext UTF8String]);
    if(event != ""){
        _proxy->event(event);
    }
}


- (void) sendWithTitle:(NSString * )title 
           description:(NSString *) desciption 
                sticky:(BOOL) sticky 
                  icon:(NSString *) icon 
              priority:(int) prio 
                 event:(NSString *) event
{

    NSData *img = nil;
    if(icon != @"") img = [[NSData alloc] initWithContentsOfFile:icon];
    
    Class GAB = NSClassFromString(@"GrowlApplicationBridge");
	if([GAB respondsToSelector:@selector(notifyWithTitle:description:notificationName:iconData:priority:isSticky:clickContext:identifier:)])
		[GAB notifyWithTitle:title
                 description:desciption
            notificationName:(NSString *)NotifierNotification
                    iconData:img
                    priority:(signed int)prio
                    isSticky:sticky
                clickContext:event
                  identifier:title];
        
}

@end
