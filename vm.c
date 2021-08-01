//
// Created by BrianBeckman on 7/31/2021.
//

#include "common.h"
#include "values.h"
#include "disasm.h"
#include "vm.h"


VM vm;


static void resetStack () {
    vm.vstackTop = vm.vstack;
}


void push (Value value) {
    *vm.vstackTop = value;
    vm.vstackTop ++;
}


Value pop () {
    vm.vstackTop --;
    return *vm.vstackTop;
}


void initVM() {
    vm.chunk = NULL;
    vm.ip = NULL;
    resetStack();
}


static InterpretResult
run() {
    // ================================================================
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define BINARY_OP(op) \
    do {              \
    double b = pop(); \
    double a = pop(); \
    push (a op b);    \
    } while (false) // syntactic trick: BINARY_OP is like a statement
    // ================================================================

    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        printf("        ");
        for (Value * slot = vm.vstack; slot < vm.vstackTop; slot++) {
            printf("[ ");
            printValue(*slot);
            printf(" ]");
        }
        printf("\n");
        disasmPrintInstr(vm.chunk,
                         (int)(vm.ip - vm.chunk->code));
#endif
        uint8_t instr;
        switch (instr = READ_BYTE()) {
            case OP_ADD:       BINARY_OP(+); break;
            case OP_SUBTRACT:  BINARY_OP(-); break;
            case OP_MULTIPLY:  BINARY_OP(*); break;
            case OP_DIVIDE:    BINARY_OP(/); break;
            case OP_NEGATE: {
                push(-pop());
                break;
            }
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                push(constant);
                break;
            }
            case OP_RETURN: {
                printValue(pop());
                return INTERPRET_OK;
            }
        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
#undef BINARY_OP
}


InterpretResult interpret(Chunk * c) {
    vm.chunk = c;
    vm.ip = vm.chunk->code;
    return run();
}


void freeVM() {

}