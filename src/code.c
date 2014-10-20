#include "ire.h"


IRE_API(ire_error_t)
ire_code_create(uint16_t base, uint16_t entry, uint16_t stack_base,
                uint16_t interrupt_base, uint16_t interrupt_size,
                uint16_t *interrupt_table, uint16_t size, uint8_t *data,
                ire_code_t **destination) {
    ire_code_t *self;

    if ((interrupt_size > 0 && interrupt_table == NULL) || (size > 0 && data == NULL) || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    self = malloc(sizeof(*self) + size);

    if (self == NULL) {
        return IRE_ERROR_OUT_OF_MEMORY;
    }

    self->base = base;
    self->entry = entry;
    self->stack_base = stack_base;
    self->interrupt_base = interrupt_base;
    self->size = size;

    memset(self->interrupt_table, 0, sizeof(self->interrupt_table));
    memcpy(self->interrupt_table, interrupt_table, interrupt_size);

    memcpy(self->data, data, size);

    *destination = self;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_code_create_from_file(FILE *stream, ire_code_t **destination) {
    if (stream == NULL || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_code_destroy(ire_code_t **self) {
    if (self == NULL || *self == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    free(*self);

    *self = NULL;

    return IRE_OK;
}
