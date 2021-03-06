//
//  KCHeadedPosition.h
//  Karel learns Objective-C
//
//  Created by Lukas Gianinazzi on 14.01.13.
//  Copyright (c) 2013 Lukas Gianinazzi. All rights reserved.
//

#import "KCPosition.h"

typedef NSString * KCOrientation;

static const KCOrientation south = @"s";
static const KCOrientation north = @"n";
static const KCOrientation west = @"w";
static const KCOrientation east = @"e";

//note: KCHeadedPosition is immutable
@interface KCHeadedPosition : KCPosition

//designated initializer
- (id)initWithX:(NSUInteger)x Y:(NSUInteger)y orientation:(KCOrientation)orientation;

- (id)initWithPosition:(KCPosition*)position orientation:(KCOrientation)orientation;

+ (KCHeadedPosition*)positionWithX:(NSUInteger)x Y:(NSUInteger)y orientation:(KCOrientation)orientation;

//format: "x y orientation"
//the orientation should equal the KCOrientation constants
//(declared in superclass)
//+ (KCHeadedPosition*)positionFromString:(NSString*)description;

@property (readonly) KCOrientation orientation;

//rotate the orientation to the left or to the right
//position remains unchanged
- (KCHeadedPosition*)rotateLeft;
- (KCHeadedPosition*)rotateRight;

//position is moved by one field
//direction of move is dependent on orientation
//orientation is unchanged
//the coordinate system is assumed to be top-left 0,0 increasing to the right and bottom (same as UIView)
- (KCHeadedPosition*)moveInDirectionOfOrientation;

//create a copy without orientation
- (KCPosition*)asUnheadedPosition;

- (NSString *)asString;

@end