#ifndef IRE_CPU_H
#define IRE_CPU_H

IRE_API(ire_error_t) ire_cpu_create(
    ire_cpu_t **destination);

IRE_API(ire_error_t) ire_cpu_destroy(
    ire_cpu_t **self);

#endif
