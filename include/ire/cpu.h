#ifndef IRE_CPU_H
#define IRE_CPU_H

IRE_API(ire_error_t) ire_cpu_create(
    ire_binary_t *binary,
    ire_cpu_t **destination);


IRE_API(ire_error_t) ire_cpu_destroy(
    ire_cpu_t **self);


IRE_API(ire_error_t) ire_cpu_load_argv(
    ire_cpu_t *self,
    int argc,
    char **argv);


IRE_API(ire_error_t) ire_cpu_run(
    ire_cpu_t *self,
    uint16_t *result);


IRE_API(ire_error_t) ire_cpu_step(
    ire_cpu_t *self);

#endif
