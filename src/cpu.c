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

    memset(self->registers, 0, sizeof(self->registers));

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


IRE_API(ire_error_t)
ire_cpu_load_argv(ire_cpu_t *self, int argc, char **argv) {
    uint16_t rsp, tmp;
    size_t size;
    int i;

    if (self == NULL || argv == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    rsp = self->registers[IRE_RSP];

    for (i = argc - 1; i >= 0; --i) {
        size = strlen(argv[i]) + 1;

        rsp -= size;

        memcpy(&(self->memory[rsp]), argv[i], size);
    }

    rsp -= sizeof(uint16_t);

    tmp = (uint16_t)argc;

    memcpy(&(self->memory[rsp]), &tmp, sizeof(tmp));

    self->registers[IRE_RSP] = rsp;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_cpu_run(ire_cpu_t *self, uint16_t *result) {
    ire_error_t error;

    if (self == NULL || result == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    while (!(self->registers[IRE_RF] & IRE_FLAGS_POWER)) {
        error = ire_cpu_step(self);

        if (error != IRE_OK) {
            return error;
        }
    }

    *result = self->registers[IRE_R4];

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_cpu_step(ire_cpu_t *self) {
    ire_error_t error;
    ire_opcode_t opcode;
    ire_instruction_t instruction;
    ire_instruction_handler_t handler;
    uint16_t rip, rsp, flags;

    if (self == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    opcode = 0;

    rip = self->registers[IRE_RIP];
    rsp = self->registers[IRE_RSP];
    flags = self->registers[IRE_RF];

    if (flags & IRE_FLAGS_INTERRUPTS_ENABLED && flags & IRE_FLAGS_INTERRUPT) {
        self->registers[IRE_RSP] -= sizeof(rip);

        memcpy(&(self->memory[rsp]), &rip, sizeof(rip));

        memcpy(
            &rip,
            &(self->memory[self->interrupt_table + (2 * self->interrupt)]),
            sizeof(rip));

        flags &= ~(IRE_FLAGS_INTERRUPT);
    }

    self->registers[IRE_RIP] = rip + 2;

    memcpy(&instruction, &(self->memory[rip]), 2);

    switch (instruction.generic >> 14) {
        case 0x00:
            opcode = (instruction.generic >> 8) & 0xff;
            break;

        case 0x01:
            opcode = (instruction.generic >> 8) & 0xfc;
            break;

        case 0x02:
        case 0x03:
            opcode = (instruction.generic >> 8) & 0xf8;
            break;

    }

    handler = ire_instruction_handler_table[opcode];

    error = handler(&instruction, self);

    if (error != IRE_OK) {
        return error;
    }

    return IRE_OK;
}
