#include "ire.h"


IRE_API(ire_error_t)
ire_cpu_create(ire_binary_t *binary, ire_cpu_t **destination) {
    ire_cpu_t *self;

    if (binary == NULL || binary->data == NULL || binary->code == NULL || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    self = malloc(sizeof(*self) + 0x10000);

    if (self == NULL) {
        return IRE_ERROR_OUT_OF_MEMORY;
    }

    self->registers[IRE_RIP] = binary->code->entry;
    self->registers[IRE_RSP] = binary->code->stack_base;

    if (binary->data->zero > 0) {
        memset(&(self->memory[binary->data->base]), 0, binary->data->zero);
    }

    memcpy(
        &(self->memory[binary->data->base + binary->data->zero]),
        binary->data->data,
        binary->data->size);

    memcpy(
        &(self->memory[binary->code->interrupt_base]),
        binary->code->interrupt_table,
        sizeof(binary->code->interrupt_table));

    memcpy(
        &(self->memory[binary->code->base]),
        binary->code->data,
        binary->code->size);

    *destination = self;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_cpu_destroy(ire_cpu_t **self) {
    if (self == NULL || *self == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    free(*self);

    *self = NULL;

    return IRE_OK;
}
