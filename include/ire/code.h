#ifndef IRE_CODE_H
#define IRE_CODE_H

IRE_API(ire_error_t) ire_code_create(
    uint16_t base,
    uint16_t entry,
    uint16_t stack_base,
    uint16_t interrupt_base,
    uint16_t interrupt_size,
    uint16_t *interrupt_table,
    uint16_t size,
    uint8_t *data,
    ire_code_t **destination);


IRE_API(ire_error_t) ire_code_destroy(
    ire_code_t **self);

#endif
