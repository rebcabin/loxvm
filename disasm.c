//
// Created by BrianBeckman on 7/31/2021.
//


#include "disasm.h"


void disasmPrintChunk (Chunk * chunk, const char * name) {
    printf ("== %s == at 0x%p\n", name, chunk);
    for (int index = 0; index < chunk->count;) {
        index = disasmPrintInstr(chunk, index);
    }
}


static int printSimpleInstr(const char * name, int index) {
    printf ("%s\n", name);
    return index + 1;
}


static int printConstantInstr(const char * name, Chunk * c, int index) {
    uint8_t iconst = c->code[index + 1];  // Value is right after the opcode.
    printf("%-16s %4d '", name, iconst);
    printValue (c->constants.values[iconst]);
    printf ("'\n");
    return index + 2;
}


int disasmPrintInstr(Chunk * chunk, int index) {
    printf("%04d ", index);
    if (index > 0 && chunk->lines[index] == chunk->lines[index - 1]) {
        printf ("   | ");
    } else {
        printf ("%4d ", chunk->lines[index]);
    }
    uint8_t instr = chunk->code[index];
    switch (instr) {
        case OP_RETURN:
            return printSimpleInstr("OP_RETURN", index);
        case OP_CONSTANT:
            return printConstantInstr("OP_CONSTANT", chunk, index);
        default:
            printf("Unknown opcode %d\n", instr);
            return index + 1;
    }
}
