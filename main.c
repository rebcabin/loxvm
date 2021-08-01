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
    writeChunk(&c, OP_NEGATE, 234);
    writeChunk(&c, OP_DIVIDE, 765);
    writeChunk(&c, OP_RETURN, 43);
    printf("******** TEST INTERPRETER *******\n");
    interpret(&c);
    freeChunk(&c);
}


static InterpretResult
interpret_source (const char * source) {
    return INTERPRET_OK;
}


static void repl() {
    static char line [1024];
    for (;;) {
        printf("lox> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }
        interpret_source(line);
    }
}


static char * readFile (const char * path) {
    FILE * file = fopen(path, "rb");

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char * buffer = (char *)malloc(fileSize + 1);
    assert (buffer != NULL);
    size_t bytesRead = fread(buffer, sizeof (char), fileSize, file);
    assert (bytesRead == fileSize);
    buffer[bytesRead] = '\0';

    fclose(file);
    return buffer;
}


void runFile (const char * path) {
    char * source = readFile(path);
    InterpretResult result = interpret_source(source);
    free (source);

    if (result == INTERPRET_COMPILE_ERROR)
        exit (65);

    if (result == INTERPRET_RUNTIME_ERROR)
        exit (75);
}


void run_lox(int argc, const char ** argv) {
    if (argc == 1) {
        repl();
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        fprintf(stderr, "Usage: lox [path]\n");
    }
}


int main(int argc, const char ** argv) {
    initVM();
    run_lox(argc, argv);


    testChunk();
    testVM();
    freeVM();


    return 0;
}
