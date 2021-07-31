//
// Created by BrianBeckman on 7/31/2021.
//

#ifndef LOXVM_VALUES_H
#define LOXVM_VALUES_H

#include "common.h"


typedef double
Value;


void printValue(Value value);


typedef struct {
    int capacity;
    int count;
    Value * values;
} ValueArray;


void initValueArray (ValueArray * values);


void freeValueArray (ValueArray * values);


void writeValueArray (ValueArray * values, Value value);


#endif //LOXVM_VALUES_H
