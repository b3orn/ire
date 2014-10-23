#ifndef IRE_OPCODES_H
#define IRE_OPCODES_H

#define IRE_OPCODE_NOP  0x00
#define IRE_OPCODE_CPY  0x01
#define IRE_OPCODE_STO  0x02
#define IRE_OPCODE_LOD  0x03
#define IRE_OPCODE_PSH  0x04
#define IRE_OPCODE_POP  0x05
#define IRE_OPCODE_CAL  0x06
#define IRE_OPCODE_JMP  0x07
#define IRE_OPCODE_IRT  0x08
#define IRE_OPCODE_RET  0x09
#define IRE_OPCODE_IRET 0x0a
#define IRE_OPCODE_CMP  0x0b
#define IRE_OPCODE_ADD  0x0c
#define IRE_OPCODE_SUB  0x0d
#define IRE_OPCODE_MUL  0x0e
#define IRE_OPCODE_DIV  0x0f
#define IRE_OPCODE_MOD  0x10
#define IRE_OPCODE_NEG  0x11
#define IRE_OPCODE_AND  0x12
#define IRE_OPCODE_OR   0x13
#define IRE_OPCODE_XOR  0x14
#define IRE_OPCODE_NOT  0x15
#define IRE_OPCODE_SHL  0x16
#define IRE_OPCODE_SHR  0x17
#define IRE_OPCODE_ROL  0x18
#define IRE_OPCODE_ROR  0x19
#define IRE_OPCODE_IN   0x1a
#define IRE_OPCODE_OUT  0x1b
#define IRE_OPCODE_HLT  0x1c
#define IRE_OPCODE_HLTI 0x1d

#define IRE_OPCODE_CMPI 0x40
#define IRE_OPCODE_ADDI 0x44
#define IRE_OPCODE_SUBI 0x48
#define IRE_OPCODE_MULI 0x4c
#define IRE_OPCODE_DIVI 0x50
#define IRE_OPCODE_MODI 0x54
#define IRE_OPCODE_ANDI 0x58
#define IRE_OPCODE_ORI  0x5c
#define IRE_OPCODE_XORI 0x60
#define IRE_OPCODE_SHLI 0x64
#define IRE_OPCODE_SHRI 0x68
#define IRE_OPCODE_ROLI 0x6c
#define IRE_OPCODE_RORI 0x70
#define IRE_OPCODE_INI  0x74
#define IRE_OPCODE_OUTI 0x78

#define IRE_OPCODE_LODI 0x80
#define IRE_OPCODE_ESC  0x88
#define IRE_OPCODE_CALI 0x90
#define IRE_OPCODE_IRTI 0x98
#define IRE_OPCODE_JMPI 0xa0


#define IRE_OP_NOP() \
    (uint16_t)(IRE_OPCODE_NOP << 8)

#define IRE_OP_CPY(DESTINATION, SOURCE) \
    (uint16_t)(IRE_OPCODE_CPY << 8 | DESTINATION << 4 | SOURCE)

#define IRE_OP_STO(DESTINATION, SOURCE) \
    (uint16_t)(IRE_OPCODE_STO << 8 | DESTINATION << 4 | SOURCE)

#define IRE_OP_LOD(DESTINATION, SOURCE) \
    (uint16_t)(IRE_OPCODE_LOD << 8 | DESTINATION << 4 | SOURCE)

#define IRE_OP_PSH(SOURCE) \
    (uint16_t)(IRE_OPCODE_PSH << 8 | SOURCE)

#define IRE_OP_POP(DESTINATION) \
    (uint16_t)(IRE_OPCODE_POP << 8 | DESTINATION)

#define IRE_OP_CAL(CONDITION, TARGET) \
    (uint16_t)(IRE_OPCODE_CAL  << 8 | CONDITION << 4 | TARGET)

#define IRE_OP_JMP(CONDITION, TARGET) \
    (uint16_t)(IRE_OPCODE_CAL  << 8 | CONDITION << 4 | TARGET)

#define IRE_OP_IRT(CONDITION, INTERRUPT) \
    (uint16_t)(IRE_OPCODE_CAL  << 8 | CONDITION << 4 | INTERRUPT)

#define IRE_OP_RET(CONDITION) \
    (uint16_t)(IRE_OPCODE_RET << 8 | CONDITION)

#define IRE_OP_IRET(CONDITION) \
    (uint16_t)(IRE_OPCODE_IRET << 8 | CONDITION)

#define IRE_OP_CMP(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_CMP << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_ADD(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_ADD << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_SUB(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_SUB << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_MUL(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_MUL << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_DIV(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_DIV << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_MOD(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_MOD << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_NEG(DESTINATION) \
    (uint16_t)(IRE_OPCODE_NEG << 8 | DESTINATION)

#define IRE_OP_AND(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_AND << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_OR(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_OR << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_XOR(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_XOR << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_NOT(DESTINATION) \
    (uint16_t)(IRE_OPCODE_NOT << 8 | DESTINATION)

#define IRE_OP_SHL(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_SHL << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_SHR(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_SHR << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_ROL(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_ROL << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_ROR(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_ROR << 8 | LEFT << 4 | RIGHT)

#define IRE_OP_IN(DESTINATION, SOURCE) \
    (uint16_t)(IRE_OPCODE_IN << 8 | DESTINATION << 4 | SOURCE)

#define IRE_OP_OUT(DESTINATION, SOURCE) \
    (uint16_t)(IRE_OPCODE_OUT << 8 | DESTINATION << 4 | SOURCE)

#define IRE_OP_HLT(MODE) \
    (uint16_t)(IRE_OPCODE_HLT << 8 | MODE)

#define IRE_OP_HLTI(MODE) \
    (uint16_t)(IRE_OPCODE_HLTI << 8 | MODE)

#define IRE_OP_CMPI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_CMPI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_ADDI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_ADDI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_SUBI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_SUBI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_MULI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_MULI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_DIVI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_DIVI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_MODI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_MODI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_ANDI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_ANDI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_ORI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_ORI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_XORI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_XORI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_SHLI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_SHLI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_SHRI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_SHRI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_ROLI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_ROLI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_RORI(LEFT, RIGHT) \
    (uint16_t)(IRE_OPCODE_RORI << 8 | RIGHT << 4 | LEFT)

#define IRE_OP_INI(DESTINATION, SOURCE) \
    (uint16_t)(IRE_OPCODE_INI << 8 | SOURCE << 4 | DESTINATION)

#define IRE_OP_OUTI(DESTINATION, SOURCE) \
    (uint16_t)(IRE_OPCODE_OUTI << 8 | DESTINATION << 4 | SOURCE)

#define IRE_OP_LODI(DESTINATION, VALUE) \
    (uint16_t)(IRE_OPCODE_LODI << 8 | (DESTINATION & 0x7) << 8 | VALUE)

#define IRE_OP_ESC(DEVICE, OPERATION) \
    (uint16_t)(IRE_OPCODE_ESC << 8 | DEVICE << 6 | OPERATION)

#define IRE_OP_CALI(ROTATION, VALUE) \
    (uint16_t)(IRE_OPCODE_CALI << 8 | ROTATION << 8 | VALUE)

#define IRE_OP_IRTI(INTERRUPT) \
    (uint16_t)(IRE_OPCODE_IRTI << 8 | INTERRUPT)

#define IRE_OP_JMPI(CONDITION, DIRECTION, TARGET) \
    (uint16_t)(IRE_OPCODE_JMPI << 8 | CONDITION << 7 | DIRECTION << 6 | TARGET)

#endif
