#ifndef IRE_INSTRUCTIONS_H
#define IRE_INSTRUCTIONS_H

extern ire_instruction_handler_t ire_instruction_handler_table[0xff];


IRE_API(ire_error_t) ire_instruction_handler_nop(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);

#endif
