//
// Created by BrianBeckman on 7/31/2021.
//

#ifndef LOXVM_VM_H
#define LOXVM_VM_H

#include "chunk.h"


typedef struct {
    Chunk * chunk;
    uint8_t * ip;
} VM;


typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;


InterpretResult interpret (Chunk * c);


void initVM();
void freeVM();


#endif //LOXVM_VM_H
