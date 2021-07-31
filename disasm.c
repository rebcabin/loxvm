//
// Created by BrianBeckman on 7/31/2021.
//


#include "disasm.h"


void disasmPrintChunk (Chunk * chunk, const char * name) {
    printf ("== %s ==\n", name);
    for (int index = 0; index < chunk->count;) {
        index = disasmPrintInstr(chunk, index);
    }
}


static int simpleInstruction(const char * name, int index) {
    printf ("%s\n", name);
    return index + 1;
}


int disasmPrintInstr(Chunk * chunk, int index) {
    printf("%04d ", index);
    uint8_t instr = chunk->code[index];
    switch (instr) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", index);
        default:
            printf("Unknown opcode %d\n", instr);
            return index + 1;
    }
}
