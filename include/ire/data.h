#ifndef IRE_DATA_H
#define IRE_DATA_H

IRE_API(ire_error_t) ire_data_create(
    uint16_t base,
    uint16_t zero,
    uint16_t size,
    uint8_t *data,
    ire_data_t **destination);


IRE_API(ire_error_t) ire_data_create_from_file(
    FILE *stream,
    ire_data_t **destination);


IRE_API(ire_error_t) ire_data_destroy(
    ire_data_t **self);


IRE_API(ire_error_t) ire_data_write_to_file(
    ire_data_t *self,
    FILE *stream);

#endif
