#include "ire.h"


ire_instruction_handler_t ire_instruction_handler_table[0xff] = {
    [IRE_OPCODE_NOP] = ire_instruction_handler_nop
};


IRE_API(ire_error_t)
ire_instruction_handler_nop(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}
