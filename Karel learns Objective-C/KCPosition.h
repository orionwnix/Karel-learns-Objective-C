//
//  KCPosition.h
//  Karel learns Objective-C
//
//  Created by Lukas Gianinazzi on 14.01.13.
//  Copyright (c) 2013 Lukas Gianinazzi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KCPosition : NSObject <NSCopying>

//designated initializer

- (id)initWithX:(NSUInteger)x Y:(NSUInteger)y;

//format: @"x y"
//precondition: x > 0 && y > 0
+ (id)positionFromString:(NSString*)description;
//compatible with positionFromString
- (NSString *)asString;

//first two values are relevant, rest is ignored
//first value must be a string -> x component
//second value must be a string -> y component
//returns nil if invalid
+ (KCPosition*)positionFromArrayOfComponentStrings:(NSArray*)components;

//note KCPosition is immutable
@property (readonly) NSUInteger x;
@property (readonly) NSUInteger y;



@end
