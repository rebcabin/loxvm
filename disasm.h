//
// Created by BrianBeckman on 7/31/2021.
//

#ifndef LOXVM_DISASM_H
#define LOXVM_DISASM_H


#include "chunk.h"


/* TODO: refactor these to build string arrays. */
void disasmPrintChunk (Chunk * chunk, const char * name);
int disasmPrintInstr(Chunk * chunk, int index);


#endif //LOXVM_DISASM_H
