//
//  KCCounter.m
//  Karel learns Objective-C
//
//  Created by Lukas Gianinazzi on 22.01.13.
//  Copyright (c) 2013 Lukas Gianinazzi. All rights reserved.
//

#import "KCCounter.h"

@interface KCCounter()

@property (nonatomic, strong) NSArray * internalCount;
@property (nonatomic, weak) KCKarel * karel;

@end



@implementation KCCounter

- (id)initWithKarel:(KCKarel *)karel
{
    self = [super init];
    if (self) {
        _karel = karel;
    } return self;
}

- (NSArray *)internalCount
{
    if (!_internalCount) {
        _internalCount = [NSArray array];
    } return _internalCount;
}


- (void)pushSlot
{
    [self pushSlotWithValue:0];
}


- (void)pushSlotWithValue:(int)value
{
    NSMutableArray * mutableCopy = [self.internalCount mutableCopy];
    
    [mutableCopy addObject:[NSNumber numberWithInt:value]];
    self.internalCount = [mutableCopy copy];
    [self.karel.world nextTurn];
}

- (void)popSlot
{
    NSAssert([self notEmpty], @"precondition: counter not empty");
    NSMutableArray * mutableCopy = [self.internalCount mutableCopy];
    [mutableCopy removeLastObject];
    self.internalCount = [mutableCopy copy];
    [self.karel.world nextTurn];
}

- (void)incrementValueAtLastSlot
{
    [self setValueAtLastSlot:[self valueAtLastSlot]+1];
}

- (void)decrementValueAtLastSlot
{
    [self setValueAtLastSlot:[self valueAtLastSlot]-1];
}

- (int)valueAtLastSlot
{
    NSAssert([self notEmpty], @"precondition: not empty");
    
    return [self valueAtSlotWithInverseIndex:0];
}


- (int)valueAtSlotWithIndex:(int)index
{
    return [[self.internalCount objectAtIndex:index] intValue];
}

- (int)valueAtSlotWithInverseIndex:(int)indexFromBehind
{
    return [self valueAtSlotWithIndex:self.numberOfSlots-indexFromBehind-1];
}


- (void)setValueAtLastSlot:(int)value
{
    NSAssert([self notEmpty], @"precondition: not empty");
    
    NSMutableArray * mutableCopy = [self.internalCount mutableCopy];
    
    [mutableCopy setObject:[NSNumber numberWithInt:value] atIndexedSubscript:self.internalCount.count-1];
    self.internalCount = [mutableCopy copy];
    
    [self.karel.world nextTurn];
}

- (void)copyLastValueToSlotWithInverseIndex:(int)indexFromBehind
{
    NSAssert([self notEmpty], @"precondition: not empty");    
    NSMutableArray * mutableCopy = [self.internalCount mutableCopy];
    
    [mutableCopy setObject:[NSNumber numberWithInt:[self valueAtLastSlot]] atIndexedSubscript:self.internalCount.count-indexFromBehind-1];
    self.internalCount = [mutableCopy copy];
    
    [self.karel.world nextTurn];
}


- (BOOL)empty
{
    return self.internalCount.count == 0;
}

- (BOOL)notEmpty
{
    return ![self empty];
}


- (int)numberOfSlots
{
    return self.internalCount.count;
}
@end
