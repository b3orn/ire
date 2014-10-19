#include "ire.h"


IRE_API(ire_error_t)
ire_cpu_create(ire_binary_t *binary, ire_cpu_t **destination) {
    if (binary == NULL || destination == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_ERROR_NOT_IMPLEMENTED;
}


IRE_API(ire_error_t)
ire_cpu_destroy(ire_cpu_t **self) {
    if (self == NULL || *self == NULL) {
        return IRE_ERROR_NULL_POINTER;
    }

    return IRE_ERROR_NOT_IMPLEMENTED;
}
