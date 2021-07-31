//
// Created by BrianBeckman on 7/31/2021.
//

#include "common.h"
#include "values.h"
#include "disasm.h"
#include "vm.h"


VM vm;


void initVM() {
    vm.chunk = NULL;
    vm.ip = NULL;
}


static InterpretResult
run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        disasmPrintInstr(vm.chunk,
                         (int)(vm.ip - vm.chunk->code));
#endif
        uint8_t instr;
        switch (instr = READ_BYTE()) {
            case OP_RETURN: {
                return INTERPRET_OK;
            }
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                printValue(constant);
                printf("\n");
                break;
            }
        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
}


InterpretResult interpret(Chunk * c) {
    vm.chunk = c;
    vm.ip = vm.chunk->code;
    return run();
}


void freeVM() {

}