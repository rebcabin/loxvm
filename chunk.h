//
// Created by BrianBeckman on 7/31/2021.
//

#ifndef LOXVM_CHUNK_H
#define LOXVM_CHUNK_H

#include "common.h"


typedef enum {
    OP_RETURN,
} OpCode;


typedef struct {
    int count;  // size_t ?
    int capacity;  // size_t ?
    uint8_t * code;
} Chunk;


void initChunk (Chunk * chunk);


void freeChunk (Chunk * chunk);


void writeChunk (Chunk * chunk, uint8_t byte);


#endif //LOXVM_CHUNK_H
