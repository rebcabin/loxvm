#include "common.h"
#include "vm.h"
#include "disasm.h"


static void buggleTestChunk(Chunk *c) {
    writeChunk(c, OP_CONSTANT, 42);
    writeChunk(c, addConstant(c, 3.14159), 42);

    writeChunk(c, OP_CONSTANT, 42);
    writeChunk(c, addConstant(c, 2.71828), 42);

    writeChunk(c, OP_RETURN, 43);
}

void
testChunk() {
    Chunk c;
    initChunk(&c);
    buggleTestChunk(&c);
    disasmPrintChunk(&c, "test chunk");
    freeChunk(&c);
}


void testVM() {
    Chunk c;
    initChunk(&c);
    buggleTestChunk(&c);
    printf("******** TEST INTERPRETER *******\n");
    interpret(&c);
    freeChunk(&c);
}


int main() {
    initVM();
    testChunk();
    testVM();
    freeVM();
    return 0;
}
