#ifndef IRE_CONDITIONS_H
#define IRE_CONDITIONS_H

#define IRE_CONDITIONS_NONE           0x00
#define IRE_CONDITIONS_EQUAL          0x01
#define IRE_CONDITIONS_NOT_EQUAL      0x02
#define IRE_CONDITIONS_GREATER        0x03
#define IRE_CONDITIONS_GREATER_EQUAL  0x04
#define IRE_CONDITIONS_LESS           0x05
#define IRE_CONDITIONS_LESS_EQUAL     0x06
#define IRE_CONDITIONS_ABOVE          0x07
#define IRE_CONDITIONS_ABOVE_EQUAL    0x08
#define IRE_CONDITIONS_BELOW          0x09
#define IRE_CONDITIONS_BELOW_EQUAL    0x0a
#define IRE_CONDITIONS_FLAG_INTERRUPT 0x0b
#define IRE_CONDITIONS_FLAG_OVERFLOW  0x0c
#define IRE_CONDITIONS_FLAG_CARRY     0x0d


IRE_API(ire_error_t) ire_conditions_check(
    uint8_t condition,
    ire_cpu_t *cpu);

#endif
