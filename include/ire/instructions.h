#ifndef IRE_INSTRUCTIONS_H
#define IRE_INSTRUCTIONS_H

#define IRE_INSTRUCTION_CPY_DESTINATION(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_CPY_SOURCE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_STO_DESTINATION(INSTRUCTION) \
    ((INSTRUCTION & 0xf) >> 4)

#define IRE_INSTRUCTION_STO_SOURCE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_LOD_DESTINATION(INSTRUCTION) \
    ((INSTRUCTION & 0xf) >> 4)

#define IRE_INSTRUCTION_LOD_SOURCE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_PSH_SOURCE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_POP_DESTINATION(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_CAL_CONDITION(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_CAL_TARGET(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_JMP_CONDITION(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_JMP_TARGET(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_IRT_CONDITION(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_IRT_INTERRUPT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_RET_CONDITION(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_IRET_CONDITION(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_CMP_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_CMP_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_ADD_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_ADD_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_SUB_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_SUB_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_MUL_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_MUL_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_DIV_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_DIV_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_MOD_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_MOD_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_NEG_VALUE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_AND_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_AND_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_OR_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_OR_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_XOR_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_XOR_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_NOT_VALUE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_SHL_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_SHL_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_SHR_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_SHR_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_ROL_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_ROL_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_ROR_LEFT(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_ROR_RIGHT(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_IN_DESTINATION(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_IN_SOURCE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_OUT_DESTINATION(INSTRUCTION) \
    ((INSTRUCTION & 0xf0) >> 4)

#define IRE_INSTRUCTION_OUT_SOURCE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_HLT_MODE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_HLTI_MODE(INSTRUCTION) \
    (INSTRUCTION & 0xff)


#define IRE_INSTRUCTION_CMPI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_CMPI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_ADDI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_ADDI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_SUBI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_SUBI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_MULI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_MULI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_DIVI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_DIVI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_MODI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_MODI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_ANDI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_ANDI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_ORI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_ORI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_XORI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_XORI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_SHLI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_SHLI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_SHRI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_SHRI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_ROLI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_ROLI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_RORI_LEFT(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_RORI_RIGHT(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_INI_DESTINATION(INSTRUCTION) \
    (INSTRUCTION & 0xf)

#define IRE_INSTRUCTION_INI_SOURCE(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)


#define IRE_INSTRUCTION_OUTI_DESTINATION(INSTRUCTION) \
    ((INSTRUCTION & 0x3f0) >> 4)

#define IRE_INSTRUCTION_OUTI_SOURCE(INSTRUCTION) \
    (INSTRUCTION & 0xf)


#define IRE_INSTRUCTION_LODI_DESTINATION(INSTRUCTION) \
    ((INSTRUCTION & 0x700) >> 8)

#define IRE_INSTRUCTION_LODI_SOURCE(INSTRUCTION) \
    (INSTRUCTION & 0xff)


#define IRE_INSTRUCTION_ESC_DEVICE(INSTRUCTION) \
    ((INSTRUCTION & 0x7c0) >> 6)

#define IRE_INSTRUCTION_ESC_OPERATION(INSTRUCTION) \
    (INSTRUCTION & 0x3f)


#define IRE_INSTRUCTION_CALI_ROTATION(INSTRUCTION) \
    ((INSTRUCTION & 0x700) >> 8)

#define IRE_INSTRUCTION_CALI_VALUE(INSTRUCTION) \
    (INSTRUCTION & 0xff)


#define IRE_INSTRUCTION_IRTI_INTERRUPT(INSTRUCTION) \
    (INSTRUCTION & 0x7ff)


#define IRE_INSTRUCTION_JMPI_CONDITION(INSTRUCTION) \
    ((INSTRUCTION & 0x780) >> 7)

#define IRE_INSTRUCTION_JMPI_DIRECTION(INSTRUCTION) \
    ((INSTRUCTION & 0x40) >> 6)

#define IRE_INSTRUCTION_JMPI_OFFSET(INSTRUCTION) \
    (INSTRUCTION & 0x3f)


extern ire_instruction_handler_t ire_instruction_handler_table[0xff];


IRE_API(ire_error_t) ire_instruction_handler_nop(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cpy(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_sto(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_lod(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_psh(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_pop(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cal(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_jmp(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_irt(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_ret(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_iret(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cmp(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_add(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_sub(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_mul(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_div(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_mod(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_neg(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_and(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_or(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_xor(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_not(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_shl(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_shr(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_rol(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_ror(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_in(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_out(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_hlt(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_hlti(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cmpi(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_addi(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_subi(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_muli(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_divi(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_modi(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_andi(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_ori(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_xori(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_shli(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_shri(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_roli(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_rori(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_ini(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_outi(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_lodi(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_esc(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_cali(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_irti(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);


IRE_API(ire_error_t) ire_instruction_handler_jmpi(
    ire_instruction_t instruction,
    ire_cpu_t *cpu);

#endif
