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
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_sto(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_lod(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_psh(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_pop(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cal(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_jmp(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_irt(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ret(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_iret(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_cmp(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_add(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_sub(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

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
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_or(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_xor(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_not(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shl(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_shr(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_rol(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_instruction_handler_ror(ire_instruction_t *instruction, ire_cpu_t *cpu) {
    if (instruction == NULL || cpu == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

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
