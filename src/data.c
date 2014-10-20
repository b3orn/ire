#include "ire.h"


IRE_API(ire_error_t)
ire_data_create(uint16_t base, uint16_t zero, uint16_t size, uint8_t *data,
                ire_data_t **destination) {
    ire_data_t *self;

    if ((size > 0 && data == NULL) || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    self = malloc(sizeof(*self) + size);

    if (self == NULL) {
        return IRE_ERROR_OUT_OF_MEMORY;
    }

    self->base = base;
    self->zero = zero;
    self->size = size;

    memcpy(self->data, data, size);

    *destination = self;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_data_create_from_file(FILE *stream, ire_data_t **destination) {
    ire_data_t *self;
    ire_data_t tmp;
    size_t size;

    if (stream == NULL || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    tmp = (ire_data_t){0, 0, 0};

    size = fread(&tmp, sizeof(tmp), 1, stream);

    if (size != 1) {
        return feof(stream) ? IRE_ERROR_END_OF_FILE : IRE_ERROR_IO;
    }

    self = malloc(sizeof(*self) + tmp.size);

    if (self == NULL) {
        return IRE_ERROR_OUT_OF_MEMORY;
    }

    memcpy(self, &tmp, sizeof(tmp));

    size = fread(self->data, 1, self->size, stream);

    if (size != self->size) {
        free(self);

        return feof(stream) ? IRE_ERROR_END_OF_FILE : IRE_ERROR_IO;
    }

    *destination = self;

    return IRE_OK;
}


IRE_API(ire_error_t)
ire_data_destroy(ire_data_t **self) {
    if (self == NULL || *self == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    free(*self);

    *self = NULL;

    return IRE_OK;
}
