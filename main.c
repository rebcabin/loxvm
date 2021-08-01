#include "common.h"
#include "vm.h"
#include "disasm.h"


static void buggleTestChunk(Chunk *c) {
    writeChunk(c, OP_CONSTANT, 42);
    writeChunk(c, addConstant(c, 3.14159), 42);

    writeChunk(c, OP_CONSTANT, 42);
    writeChunk(c, addConstant(c, 2.71828), 42);
}

void
testChunk() {
    Chunk c;
    initChunk(&c);
    buggleTestChunk(&c);
    writeChunk(&c, OP_RETURN, 43);
    disasmPrintChunk(&c, "test chunk");
    freeChunk(&c);
}


void testVM() {
    Chunk c;
    initChunk(&c);
    buggleTestChunk(&c);
    writeChunk(&c, OP_NEGATE, 1234);
    writeChunk(&c, OP_DIVIDE, 765);
    writeChunk(&c, OP_RETURN, 43);
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
