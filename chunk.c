//
// Created by BrianBeckman on 7/31/2021.
//

#include "chunk.h"
#include "memory.h"


void
initChunk (Chunk * chunk) {
    assert (chunk != NULL);
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    initValueArray(&chunk->constants);
}


void
freeChunk (Chunk * chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}


void
writeChunk (Chunk * chunk, uint8_t byte) {
    if (chunk->capacity < chunk->count + 1){
        int oldCap = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCap);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCap, chunk->capacity);
    }
    chunk->code[chunk->count] = byte;
    chunk->count++;
}


int addConstant(Chunk * chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}
