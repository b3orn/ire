#include "ire.h"


ire_instruction_handler_t ire_instruction_handler_table[0xff] = {
    [IRE_OPCODE_NOP]  = ire_instruction_handler_nop,
    [IRE_OPCODE_CPY]  = ire_instruction_handler_cpy,
    [IRE_OPCODE_STO]  = ire_instruction_handler_sto,
    [IRE_OPCODE_LOD]  = ire_instruction_handler_lod,
    [IRE_OPCODE_PSH]  = ire_instruction_handler_psh,
    [IRE_OPCODE_POP]  = ire_instruction_handler_pop,
    [IRE_OPCODE_CAL]  = ire_instruction_handler_cal,
    [IRE_OPCODE_JMP]  = ire_instruction_handler_jmp,
    [IRE_OPCODE_IRT]  = ire_instruction_handler_irt,
    [IRE_OPCODE_RET]  = ire_instruction_handler_ret,
    [IRE_OPCODE_IRET] = ire_instruction_handler_iret,
    [IRE_OPCODE_CMP]  = ire_instruction_handler_cmp,
    [IRE_OPCODE_ADD]  = ire_instruction_handler_add,
    [IRE_OPCODE_SUB]  = ire_instruction_handler_sub,
    [IRE_OPCODE_MUL]  = ire_instruction_handler_mul,
    [IRE_OPCODE_DIV]  = ire_instruction_handler_div,
    [IRE_OPCODE_MOD]  = ire_instruction_handler_mod,
    [IRE_OPCODE_NEG]  = ire_instruction_handler_neg,
    [IRE_OPCODE_AND]  = ire_instruction_handler_and,
    [IRE_OPCODE_OR]   = ire_instruction_handler_or,
    [IRE_OPCODE_XOR]  = ire_instruction_handler_xor,
    [IRE_OPCODE_NOT]  = ire_instruction_handler_not,
    [IRE_OPCODE_SHL]  = ire_instruction_handler_shl,
    [IRE_OPCODE_SHR]  = ire_instruction_handler_shr,
    [IRE_OPCODE_ROL]  = ire_instruction_handler_rol,
    [IRE_OPCODE_ROR]  = ire_instruction_handler_ror,
    [IRE_OPCODE_IN]   = ire_instruction_handler_in,
    [IRE_OPCODE_OUT]  = ire_instruction_handler_out,
    [IRE_OPCODE_HLT]  = ire_instruction_handler_hlt,
    [IRE_OPCODE_HLTI] = ire_instruction_handler_hlti,
    [IRE_OPCODE_CMPI] = ire_instruction_handler_cmpi,
    [IRE_OPCODE_ADDI] = ire_instruction_handler_addi,
    [IRE_OPCODE_SUBI] = ire_instruction_handler_subi,
    [IRE_OPCODE_MULI] = ire_instruction_handler_muli,
    [IRE_OPCODE_DIVI] = ire_instruction_handler_divi,
    [IRE_OPCODE_MODI] = ire_instruction_handler_modi,
    [IRE_OPCODE_ANDI] = ire_instruction_handler_andi,
    [IRE_OPCODE_ORI]  = ire_instruction_handler_ori,
    [IRE_OPCODE_XORI] = ire_instruction_handler_xori,
    [IRE_OPCODE_SHLI] = ire_instruction_handler_shli,
    [IRE_OPCODE_SHRI] = ire_instruction_handler_shri,
    [IRE_OPCODE_ROLI] = ire_instruction_handler_roli,
    [IRE_OPCODE_RORI] = ire_instruction_handler_rori,
    [IRE_OPCODE_INI]  = ire_instruction_handler_ini,
    [IRE_OPCODE_OUTI] = ire_instruction_handler_outi,
    [IRE_OPCODE_LODI] = ire_instruction_handler_lodi,
    [IRE_OPCODE_ESC]  = ire_instruction_handler_esc,
    [IRE_OPCODE_CALI] = ire_instruction_handler_cali,
    [IRE_OPCODE_IRTI] = ire_instruction_handler_irti,
    [IRE_OPCODE_JMPI] = ire_instruction_handler_jmpi
};


IRE_API(ire_error_t)
ire_instruction_handler_nop(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cpy(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, source, destination;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    source = IRE_INSTRUCTION_CPY_SOURCE(instruction);
    destination = IRE_INSTRUCTION_CPY_DESTINATION(instruction);

    tmp = cpu->registers[source];

    cpu->registers[destination] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_sto(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, source, destination;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    source = IRE_INSTRUCTION_STO_SOURCE(instruction);
    destination = IRE_INSTRUCTION_STO_DESTINATION(instruction);

    tmp = cpu->registers[source];

    memcpy(&(cpu->memory[destination]), &tmp, sizeof(tmp));

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_lod(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, source, destination;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    source = IRE_INSTRUCTION_LOD_SOURCE(instruction);
    destination = IRE_INSTRUCTION_LOD_DESTINATION(instruction);

    memcpy(&tmp, &(cpu->memory[source]), sizeof(tmp));

    cpu->registers[destination] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_psh(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, source, rsp;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    source = IRE_INSTRUCTION_PSH_SOURCE(instruction);

    tmp = cpu->registers[source];
    rsp = cpu->registers[IRE_RSP] - sizeof(tmp);

    memcpy(&(cpu->memory[rsp]), &tmp, sizeof(tmp));

    cpu->registers[IRE_RSP] = rsp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_pop(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, destination, rsp;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    destination = IRE_INSTRUCTION_POP_DESTINATION(instruction);

    rsp = cpu->registers[IRE_RSP];

    memcpy(&tmp, &(cpu->memory[rsp]), sizeof(tmp));

    cpu->registers[destination] = tmp;
    cpu->registers[IRE_RSP] = rsp + sizeof(tmp);

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cal(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint8_t condition;
    uint16_t tmp, target, rip, rsp;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    condition = IRE_INSTRUCTION_CAL_CONDITION(instruction);
    target = IRE_INSTRUCTION_CAL_TARGET(instruction);

    if (ire_conditions_check(condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    rip = cpu->registers[IRE_RIP];
    rsp = cpu->registers[IRE_RSP] - sizeof(rip);
    tmp = cpu->registers[target];

    memcpy(&(cpu->memory[rsp]), &rip, sizeof(rip));

    cpu->registers[IRE_RSP] = rsp;
    cpu->registers[IRE_RIP] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_jmp(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint8_t condition;
    uint16_t tmp, target;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    condition = IRE_INSTRUCTION_JMP_CONDITION(instruction);
    target = IRE_INSTRUCTION_JMP_TARGET(instruction);

    if (ire_conditions_check(condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    tmp = cpu->registers[target];
    cpu->registers[IRE_RIP] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_irt(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint8_t condition;
    uint16_t tmp, target;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    condition = IRE_INSTRUCTION_JMP_CONDITION(instruction);
    target = IRE_INSTRUCTION_JMP_TARGET(instruction);

    if (ire_conditions_check(condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    tmp = cpu->registers[target];
    cpu->registers[IRE_RIP] = tmp;

    cpu->registers[IRE_RF] |= IRE_FLAGS_INTERRUPT;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ret(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint8_t condition;
    uint16_t tmp, rsp;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    condition = IRE_INSTRUCTION_RET_CONDITION(instruction);

    if (ire_conditions_check(condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    rsp = cpu->registers[IRE_RSP];

    memcpy(&tmp, &(cpu->memory[rsp]), sizeof(tmp));

    cpu->registers[IRE_RIP] = tmp;
    cpu->registers[IRE_RSP] = rsp + sizeof(tmp);

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_iret(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint8_t condition;
    uint16_t tmp, rsp;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    condition = IRE_INSTRUCTION_IRET_CONDITION(instruction);

    if (ire_conditions_check(condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    rsp = cpu->registers[IRE_RSP];

    memcpy(&tmp, &(cpu->memory[rsp]), sizeof(tmp));

    cpu->registers[IRE_RIP] = tmp;
    cpu->registers[IRE_RSP] = rsp + sizeof(tmp);

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cmp(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t left, right, rf;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_CMP_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_CMP_RIGHT(instruction)];
    rf = 0;

    rf |= left == right ? (1 << 0) : 0;
    rf |= (int16_t)left > (int16_t)right ? (1 << 1) : 0;
    rf |= (int16_t)left < (int16_t)right ? (1 << 2) : 0;
    rf |= left > right ? (1 << 3) : 0;
    rf |= left < right ? (1 << 4) : 0;

    cpu->registers[IRE_RF] = rf;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_add(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t left, right, rf, carry;
    int32_t value;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    rf = cpu->registers[IRE_RF];
    left = cpu->registers[IRE_INSTRUCTION_ADD_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_ADD_RIGHT(instruction)];
    carry = rf & IRE_FLAGS_CARRY ? 1 : 0;
    value = left + right + carry;

    if ((value & 0xffff) != value) {
        cpu->registers[IRE_RF] |= IRE_FLAGS_CARRY;
        cpu->registers[IRE_RF] |= IRE_FLAGS_OVERFLOW;
    } else {
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_CARRY);
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_OVERFLOW);
    }

    cpu->registers[IRE_INSTRUCTION_ADD_LEFT(instruction)] = value & 0xffff;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_sub(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t left, right, rf, borrow;
    int32_t value;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    rf = cpu->registers[IRE_RF];
    left = cpu->registers[IRE_INSTRUCTION_SUB_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_SUB_RIGHT(instruction)];
    borrow = rf & IRE_FLAGS_BORROW ? 1 : 0;
    value = left - right - borrow;

    if ((value & 0xffff) != value) {
        cpu->registers[IRE_RF] |= IRE_FLAGS_BORROW;
        cpu->registers[IRE_RF] |= IRE_FLAGS_OVERFLOW;
    } else {
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_BORROW);
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_OVERFLOW);
    }

    cpu->registers[IRE_INSTRUCTION_SUB_LEFT(instruction)] = value & 0xffff;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_mul(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_div(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_mod(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_neg(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, value;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    value = IRE_INSTRUCTION_NEG_VALUE(instruction);
    tmp = -(cpu->registers[value]);

    cpu->registers[value] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_and(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_AND_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_AND_RIGHT(instruction)];
    tmp = left & right;

    cpu->registers[IRE_INSTRUCTION_AND_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_or(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_OR_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_OR_RIGHT(instruction)];
    tmp = left | right;

    cpu->registers[IRE_INSTRUCTION_OR_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_xor(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_XOR_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_XOR_RIGHT(instruction)];
    tmp = left ^ right;

    cpu->registers[IRE_INSTRUCTION_XOR_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_not(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t value;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    value = cpu->registers[IRE_INSTRUCTION_NOT_VALUE(instruction)];

    cpu->registers[IRE_INSTRUCTION_NOT_VALUE(instruction)] = ~value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shl(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_SHL_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_SHL_RIGHT(instruction)];
    tmp = (uint16_t)((left << right) & 0xffff);

    cpu->registers[IRE_INSTRUCTION_SHL_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shr(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_SHR_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_SHR_RIGHT(instruction)];
    tmp = left >> right;

    cpu->registers[IRE_INSTRUCTION_SHR_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_rol(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_ROL_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_ROL_RIGHT(instruction)];
    tmp = (uint16_t)(left >> right | left << (16 - right));

    cpu->registers[IRE_INSTRUCTION_ROL_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ror(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_ROR_LEFT(instruction)];
    right = cpu->registers[IRE_INSTRUCTION_ROR_RIGHT(instruction)];
    tmp = (uint16_t)(left << right | left >> (16 - right));

    cpu->registers[IRE_INSTRUCTION_ROR_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_in(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_out(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_hlt(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_hlti(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_cmpi(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t left, right, rf;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_CMPI_LEFT(instruction)];
    right = IRE_INSTRUCTION_CMPI_RIGHT(instruction);
    rf = 0;

    rf |= left == right ? (1 << 0) : 0;
    rf |= (int16_t)left > (int16_t)right ? (1 << 1) : 0;
    rf |= (int16_t)left < (int16_t)right ? (1 << 2) : 0;
    rf |= left > right ? (1 << 3) : 0;
    rf |= left < right ? (1 << 4) : 0;

    cpu->registers[IRE_RF] = rf;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_addi(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t left, right, rf, carry;
    int32_t value;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    rf = cpu->registers[IRE_RF];
    left = cpu->registers[IRE_INSTRUCTION_ADDI_LEFT(instruction)];
    right = IRE_INSTRUCTION_ADDI_RIGHT(instruction);
    carry = rf & IRE_FLAGS_CARRY ? 1 : 0;
    value = left + right + carry;

    if ((value & 0xffff) != value) {
        cpu->registers[IRE_RF] |= IRE_FLAGS_CARRY;
        cpu->registers[IRE_RF] |= IRE_FLAGS_OVERFLOW;
    } else {
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_CARRY);
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_OVERFLOW);
    }

    cpu->registers[IRE_INSTRUCTION_ADDI_LEFT(instruction)] = value & 0xffff;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_subi(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t left, right, rf, borrow;
    int32_t value;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    rf = cpu->registers[IRE_RF];
    left = cpu->registers[IRE_INSTRUCTION_SUBI_LEFT(instruction)];
    right = IRE_INSTRUCTION_SUBI_RIGHT(instruction);
    borrow = rf & IRE_FLAGS_BORROW ? 1 : 0;
    value = left - right - borrow;

    if ((value & 0xffff) != value) {
        cpu->registers[IRE_RF] |= IRE_FLAGS_BORROW;
        cpu->registers[IRE_RF] |= IRE_FLAGS_OVERFLOW;
    } else {
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_BORROW);
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_OVERFLOW);
    }

    cpu->registers[IRE_INSTRUCTION_SUBI_LEFT(instruction)] = value & 0xffff;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_muli(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_divi(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_modi(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_andi(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_ANDI_LEFT(instruction)];
    right = IRE_INSTRUCTION_ANDI_RIGHT(instruction);
    tmp = left & right;

    cpu->registers[IRE_INSTRUCTION_ANDI_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ori(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_ORI_LEFT(instruction)];
    right = IRE_INSTRUCTION_ORI_RIGHT(instruction);
    tmp = left | right;

    cpu->registers[IRE_INSTRUCTION_ORI_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_xori(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_XORI_LEFT(instruction)];
    right = IRE_INSTRUCTION_XORI_RIGHT(instruction);
    tmp = left ^ right;

    cpu->registers[IRE_INSTRUCTION_XORI_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shli(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_SHLI_LEFT(instruction)];
    right = IRE_INSTRUCTION_SHLI_RIGHT(instruction);
    tmp = (uint16_t)((left << right) & 0xffff);

    cpu->registers[IRE_INSTRUCTION_SHLI_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shri(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_SHRI_LEFT(instruction)];
    right = IRE_INSTRUCTION_SHRI_RIGHT(instruction);
    tmp = left >> right;

    cpu->registers[IRE_INSTRUCTION_SHRI_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_roli(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_ROLI_LEFT(instruction)];
    right = IRE_INSTRUCTION_ROLI_RIGHT(instruction);
    tmp = (uint16_t)(left >> right | left << (16 - right));

    cpu->registers[IRE_INSTRUCTION_ROLI_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_rori(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, left, right;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    left = cpu->registers[IRE_INSTRUCTION_RORI_LEFT(instruction)];
    right = IRE_INSTRUCTION_RORI_RIGHT(instruction);
    tmp = (uint16_t)(left << right | left >> (16 - right));

    cpu->registers[IRE_INSTRUCTION_RORI_LEFT(instruction)] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ini(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_outi(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_lodi(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t destination, source;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    destination = IRE_INSTRUCTION_LODI_DESTINATION(instruction);
    source = IRE_INSTRUCTION_LODI_SOURCE(instruction);

    cpu->registers[0x8 | destination] = source;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_esc(ire_instruction_t instruction, ire_cpu_t *cpu) {
    IRE_UNUSED(instruction);

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    /* TODO */

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_instruction_handler_cali(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t tmp, value, rotation, rip, rsp;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    rip = cpu->registers[IRE_RIP];
    rsp = cpu->registers[IRE_RSP] - sizeof(rip);
    rotation = IRE_INSTRUCTION_CALI_ROTATION(instruction);
    value = IRE_INSTRUCTION_CALI_VALUE(instruction);
    tmp = (uint16_t)(((value >> (2 * rotation)) << 1) |
        ((value << (16 - (2 * rotation))) & 0xffff));

    memcpy(&(cpu->memory[rsp]), &rip, sizeof(rip));

    cpu->registers[IRE_RSP] = rsp;
    cpu->registers[IRE_RIP] = tmp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_irti(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint16_t interrupt;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    interrupt = IRE_INSTRUCTION_IRTI_INTERRUPT(instruction);

    cpu->interrupt = interrupt;

    cpu->registers[IRE_RF] |= IRE_FLAGS_INTERRUPT;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_jmpi(ire_instruction_t instruction, ire_cpu_t *cpu) {
    uint8_t condition;
    uint16_t tmp, direction, offset, rip;

    if (cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    condition = IRE_INSTRUCTION_JMPI_CONDITION(instruction);
    direction = IRE_INSTRUCTION_JMPI_DIRECTION(instruction);
    offset = IRE_INSTRUCTION_JMPI_OFFSET(instruction) * sizeof(rip);

    if (ire_conditions_check(condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    rip = cpu->registers[IRE_RIP] - sizeof(rip);
    tmp = direction ? rip - offset : rip + offset;
    cpu->registers[IRE_RIP] = tmp;

    return IRE_OK;
}
