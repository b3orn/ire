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
ire_instruction_handler_nop(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cpy(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_cpy_t cpy;
    uint16_t value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    cpy = instruction->cpy;
    value = cpu->registers[cpy.source];
    cpu->registers[cpy.destination] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_sto(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_sto_t sto;
    uint16_t value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    sto = instruction->sto;
    value = cpu->registers[sto.source];

    memcpy(&(cpu->memory[sto.destination]), &value, sizeof(value));

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_lod(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_lod_t lod;
    uint16_t value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    lod = instruction->lod;

    memcpy(&value, &(cpu->memory[lod.source]), sizeof(value));

    cpu->registers[lod.destination] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_psh(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_psh_t psh;
    uint16_t value, rsp;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    psh = instruction->psh;
    value = cpu->registers[psh.source];
    rsp = cpu->registers[IRE_RSP] - sizeof(value);

    memcpy(&(cpu->memory[rsp]), &value, sizeof(value));

    cpu->registers[IRE_RSP] = rsp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_pop(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_pop_t pop;
    uint16_t value, rsp;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    pop = instruction->pop;
    rsp = cpu->registers[IRE_RSP];

    memcpy(&value, &(cpu->memory[rsp]), sizeof(value));

    cpu->registers[pop.destination] = value;
    cpu->registers[IRE_RSP] = rsp + sizeof(value);

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cal(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_cal_t cal;
    uint16_t value, rip, rsp;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    cal = instruction->cal;

    if (ire_conditions_check(cal.condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    rip = cpu->registers[IRE_RIP];
    rsp = cpu->registers[IRE_RSP] - sizeof(rip);
    value = cpu->registers[cal.target];

    memcpy(&(cpu->memory[rsp]), &rip, sizeof(rip));

    cpu->registers[IRE_RSP] = rsp;
    cpu->registers[IRE_RIP] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_jmp(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_jmp_t jmp;
    uint16_t value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    jmp = instruction->jmp;

    if (ire_conditions_check(jmp.condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    value = cpu->registers[jmp.target];
    cpu->registers[IRE_RIP] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_irt(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_irt_t irt;
    uint16_t value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    irt = instruction->irt;

    if (ire_conditions_check(irt.condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    value = cpu->registers[irt.interrupt];
    cpu->interrupt = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ret(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_ret_t ret;
    uint16_t value, rsp;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    ret = instruction->ret;

    if (ire_conditions_check(ret.condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    rsp = cpu->registers[IRE_RSP];

    memcpy(&value, &(cpu->memory[rsp]), sizeof(value));

    cpu->registers[IRE_RIP] = value;
    cpu->registers[IRE_RSP] = rsp + sizeof(value);

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_iret(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_iret_t iret;
    uint16_t value, rsp;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    iret = instruction->iret;

    if (ire_conditions_check(iret.condition, cpu) != IRE_OK) {
        return IRE_OK;
    }

    rsp = cpu->registers[IRE_RSP];

    memcpy(&value, &(cpu->memory[rsp]), sizeof(value));

    cpu->registers[IRE_RIP] = value;
    cpu->registers[IRE_RSP] = rsp + sizeof(value);

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cmp(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_cmp_t cmp;
    uint16_t left, right, rf;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    cmp = instruction->cmp;
    left = cpu->registers[cmp.left];
    right = cpu->registers[cmp.right];
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
ire_instruction_handler_add(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_add_t add;
    uint16_t left, right;
    uint32_t value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    add = instruction->add;
    left = cpu->registers[add.left];
    right = cpu->registers[add.right];

    value = left + right;

    if ((value & 0xffff) == value) {
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_CARRY);
    } else {
        cpu->registers[IRE_RF] |= IRE_FLAGS_CARRY;
    }

    cpu->registers[add.left] = value & 0xffff;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_sub(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_sub_t sub;
    uint16_t left, right;
    uint32_t value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    sub = instruction->sub;
    left = cpu->registers[sub.left];
    right = cpu->registers[sub.right];

    value = left - right;

    if ((value & 0xffff) == value) {
        cpu->registers[IRE_RF] &= ~(IRE_FLAGS_CARRY);
    } else {
        cpu->registers[IRE_RF] |= IRE_FLAGS_BORROW;
    }

    cpu->registers[sub.left] = value & 0xffff;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_mul(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_div(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_mod(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_neg(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_and(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_and_t and;
    uint16_t left, right, value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    and = instruction->and;
    left = cpu->registers[and.left];
    right = cpu->registers[and.right];
    value = left & right;

    cpu->registers[and.left] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_or(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_or_t or;
    uint16_t left, right, value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    or = instruction->or;
    left = cpu->registers[or.left];
    right = cpu->registers[or.right];
    value = left | right;

    cpu->registers[or.left] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_xor(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_xor_t xor;
    uint16_t left, right, value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    xor = instruction->xor;
    left = cpu->registers[xor.left];
    right = cpu->registers[xor.right];
    value = left ^ right;

    cpu->registers[xor.left] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_not(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_not_t not;
    uint16_t value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    not = instruction->not;
    value = cpu->registers[not.destination];

    cpu->registers[not.destination] = ~value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shl(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_shl_t shl;
    uint16_t left, right, value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    shl = instruction->shl;
    left = cpu->registers[shl.left];
    right = cpu->registers[shl.right];
    value = (uint16_t)(left << right);

    cpu->registers[shl.left] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shr(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_shr_t shr;
    uint16_t left, right, value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    shr = instruction->shr;
    left = cpu->registers[shr.left];
    right = cpu->registers[shr.right];
    value = left >> right;

    cpu->registers[shr.left] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_rol(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_rol_t rol;
    uint16_t left, right, value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    rol = instruction->rol;
    left = cpu->registers[rol.left];
    right = cpu->registers[rol.right];
    value = (uint16_t)(left >> right | left << (16 - right));

    cpu->registers[rol.left] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ror(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    ire_instruction_ror_t ror;
    uint16_t left, right, value;

    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    ror = instruction->ror;
    left = cpu->registers[ror.left];
    right = cpu->registers[ror.right];
    value = (uint16_t)(left << right | left >> (16 - right));

    cpu->registers[ror.left] = value;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_in(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_out(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_hlt(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_hlti(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cmpi(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_addi(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_subi(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_muli(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_divi(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_modi(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_andi(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ori(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_xori(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shli(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shri(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_roli(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_rori(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ini(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_outi(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_lodi(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_esc(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cali(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_irti(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_jmpi(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}
