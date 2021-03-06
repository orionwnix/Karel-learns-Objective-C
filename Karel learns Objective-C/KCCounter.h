//
//  KCCounter.h
//  Karel learns Objective-C
//
//  Created by Lukas Gianinazzi on 22.01.13.
//  Copyright (c) 2013 Lukas Gianinazzi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KCKarel.h"

@class KCKarel;

@interface KCCounter : NSObject

- (id)initWithKarel:(KCKarel*)karel;

//makes a new slot available for storage
//the value of the new slot is 0
- (void)pushSlot;

//makes a new slot available for storage and sets its value
- (void)pushSlotWithValue:(int)value;

//precondition: not empty
- (void)popSlot;


//precondition: not empty
- (int)valueAtLastSlot;//value is 0 if no value set

//indeces start with 0
//precondition: index < self.numberOfSlots
- (int)valueAtSlotWithIndex:(int)index;

//access a value counting from the end of the stack of slots
//if indexFromBehind is 0, the method will return the same as valueAtLastSlot:
//precondition: indexFromBehind < numberOfSlots
- (int)valueAtSlotWithInverseIndex:(int)indexFromBehind;


//precondition: not empty
//add one to the last slot
- (void)incrementValueAtLastSlot;

//precondition: not empty
//subtract one from the last slot
- (void)decrementValueAtLastSlot;

//precondition: not empty
- (void)setValueAtLastSlot:(int)value;

//copies the last value to the specified position (counted from behind)
- (void)copyLastValueToSlotWithInverseIndex:(int)indexFromBehind;


- (BOOL)empty;

- (BOOL)notEmpty;

- (int)numberOfSlots;

@end
