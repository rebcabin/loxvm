//
// Created by BrianBeckman on 7/31/2021.
//

#include "values.h"
#include "memory.h"


void
printValue(Value value)
{
    printf("%g", value);
}


void
initValueArray (ValueArray * values) {
    assert (values != NULL);
    values->count = 0;
    values->capacity = 0;
    values->values = NULL;
}


void
freeValueArray (ValueArray * values) {
    FREE_ARRAY(uint8_t, values->values, values->capacity);
    initValueArray(values);
}


void
writeValueArray (ValueArray * values, Value value) {
    if (values->capacity < values->count + 1){
        int oldCap = values->capacity;
        values->capacity = GROW_CAPACITY(oldCap);
        values->values = GROW_ARRAY(
                Value,
                values->values,
                oldCap,
                values->capacity);
    }
    values->values[values->count] = value;
    values->count++;
}