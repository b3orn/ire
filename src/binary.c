#include "ire.h"


IRE_API(ire_error_t)
ire_binary_create(ire_code_t *code, ire_data_t *data, ire_binary_t **destination) {
    if (code == NULL || data == NULL || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_binary_create_from_file(FILE *stream, ire_binary_t **destination) {
    if (stream == NULL || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }
    
    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_binary_destroy(ire_binary_t **self) {
    if (self == NULL || *self == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_ERROR_NOT_IMPLEMENTED;
}
