#ifndef IRE_INSTRUCTIONS_H
#define IRE_INSTRUCTIONS_H

extern ire_instruction_handler_t ire_instruction_handler_table[0xff];


IRE_API(ire_error_t) ire_instruction_handler_nop(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cpy(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_sto(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_lod(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_psh(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_pop(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cal(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_jmp(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_irt(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_ret(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_iret(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cmp(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_add(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_sub(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_mul(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_div(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_mod(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_neg(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_and(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_or(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_xor(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_not(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_shl(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_shr(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_rol(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_ror(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_in(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_out(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_hlt(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_hlti(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cmpi(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_addi(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_subi(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_muli(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_divi(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_modi(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_andi(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_ori(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_xori(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_shli(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_shri(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_roli(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_rori(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_ini(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_outi(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_lodi(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_esc(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cali(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_irti(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_jmpi(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);

#endif
