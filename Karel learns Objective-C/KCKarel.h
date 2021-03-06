//
//  KCKarel.h
//  Karel learns Objective-C
//
//  Created by Lukas Gianinazzi on 14.01.13.
//  Copyright (c) 2013 Lukas Gianinazzi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KCWorld.h"
#import "KCCounter.h"
#import "KCColorPalette.h"

typedef NSUInteger KCCount;
static KCCount const KCUnlimited = INT_MAX;


@class KCWorld;
@class KCCounter;

@interface KCKarel : NSObject <NSCopying>

//subclass Karel and overwrite run
- (void)run;

//basic operations:

- (void)move;//precondition: frontIsClear
- (void)turnLeft;
- (void)pickBeeper;//precondition: beepersPresent
- (void)putBeeper;//precondition: beepersInBag


//colors

- (void)paintCorner:(UIColor*)color;

//conditions

- (BOOL)beepersPresent;
- (BOOL)noBeepersPresent;

@property (readonly) BOOL beepersInBag;
@property (readonly) BOOL noBeepersInBag;

- (BOOL)frontIsClear;
- (BOOL)leftIsClear;
- (BOOL)rightIsClear;

- (BOOL)frontIsBlocked;
- (BOOL)leftIsBlocked;
- (BOOL)rightIsBlocked;


//orientation

- (BOOL)facingEast;
- (BOOL)facingWest;
- (BOOL)facingNorth;
- (BOOL)facingSouth;

//creation and export:
- (id)initWithWorld:(KCWorld *)world numberOfBeepers:(KCCount)count;

+ (KCKarel *)karelFromString:(NSString *)description inWorld:(KCWorld*)world;
- (NSString *)asString;


//when karel executes an operation, it notifies the world to update karels position in it
@property (nonatomic, weak) KCWorld * world;


@end
