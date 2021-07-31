#include "common.h"
#include "chunk.h"
#include "disasm.h"


void
testChunk() {
    Chunk c;
    initChunk(&c);

    int constant = addConstant(&c, 3.14159);
    writeChunk(&c, OP_CONSTANT);
    writeChunk(&c, constant);

    writeChunk(&c, OP_RETURN);
    disasmPrintChunk(&c, "test chunk");
    freeChunk(&c);
}


int main() {
    printf("test chunk!\n");
    testChunk();
    return 0;
}
