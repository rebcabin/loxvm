#include "common.h"
#include "chunk.h"
#include "disasm.h"


void
testChunk() {
    Chunk c;
    initChunk(&c);
    writeChunk(&c, OP_RETURN);
    disasmPrintChunk(&c, "test chunk");
    freeChunk(&c);
}


int main() {
    printf("test chunk!\n");
    testChunk();
    return 0;
}
