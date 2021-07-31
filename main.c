#include "common.h"
#include "chunk.h"
#include "disasm.h"


void
testChunk() {
    Chunk c;
    initChunk(&c);

    writeChunk(&c, OP_CONSTANT, 42);
    writeChunk(&c, addConstant(&c, 3.14159), 42);

    writeChunk(&c, OP_CONSTANT, 42);
    writeChunk(&c, addConstant(&c, 2.71828), 42);

    writeChunk(&c, OP_RETURN, 43);
    disasmPrintChunk(&c, "test chunk");
    freeChunk(&c);
}


int main() {
    printf("test chunk!\n");
    testChunk();
    return 0;
}
