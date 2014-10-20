#include "ire.h"


IRE_API(ire_error_t)
ire_binary_create(ire_data_t *data, ire_code_t *code,
                  ire_binary_t **destination) {
    if (data == NULL || code == NULL || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_binary_create_from_file(FILE *stream, ire_binary_t **destination) {
    ire_binary_t *self;
    ire_error_t error;
    size_t size;

    if (stream == NULL || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    self = malloc(sizeof(*self));

    if (self == NULL) {
        return IRE_ERROR_OUT_OF_MEMORY;
    }

    size = fread(self, sizeof(*self) - (2 * sizeof(void*)), 1, stream);

    if (size != 1) {
        error = feof(stream) ? IRE_ERROR_END_OF_FILE : IRE_ERROR_FILE_READ;

        goto fail;
    }

    error = ire_binary_validate(self);

    if (error != IRE_OK) {
        goto fail;
    }

    error = ire_data_create_from_file(stream, &(self->data));

    if (error != IRE_OK) {
        goto fail;
    }

    error = ire_code_create_from_file(stream, &(self->code));

    if (error != IRE_OK) {
        goto fail;
    }

    return IRE_OK;

fail:
    free(self);

    return error;
}


IRE_API(ire_error_t)
ire_binary_destroy(ire_binary_t **self) {
    if (self == NULL || *self == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    ire_data_destroy(&((*self)->data));
    ire_code_destroy(&((*self)->code));

    free(*self);

    self = NULL;

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_binary_write_to_file(ire_binary_t *self, FILE *stream) {
    ire_error_t error;
    size_t size;

    if (self == NULL || stream == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    size = fwrite(self, sizeof(*self) - (2 * sizeof(void*)), 1, stream);

    if (size != 1) {
        return IRE_ERROR_FILE_WRITE;
    }

    error = ire_data_write_to_file(self->data, stream);

    if (error != IRE_OK) {
        return error;
    }

    error = ire_code_write_to_file(self->code, stream);

    if (error != IRE_OK) {
        return error;
    }

    return IRE_OK;
}



IRE_API(ire_error_t)
ire_binary_validate(ire_binary_t *self) {
    if (self == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }
    
    if (memcmp(self->magic, "ire", 4) != 0) {
        return IRE_ERROR_UNKNOWN_FORMAT;
    }

    if (self->version != IRE_VERSION) {
        return IRE_ERROR_UNSUPPORTED_VERSION;
    }
    
    return IRE_OK;
}
