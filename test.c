#include "ire.h"


int main(void) {
    FILE *stream;
    ire_error_t error;
    ire_code_t *code;
    ire_data_t *data;
    ire_binary_t *binary;
    uint8_t tmp_data[0x0800] = {0};
    ire_instruction_t tmp_code[] = {
        IRE_OP_LODI(IRE_R8, 255),
        IRE_OP_LODI(IRE_R9, 255),
        IRE_OP_LODI(IRE_R10, 0x80),
        IRE_OP_SHLI(IRE_R10, 8),
        IRE_OP_CPY(IRE_R4, IRE_R8),
        IRE_OP_CPY(IRE_R5, IRE_R9),
        IRE_OP_ADD(IRE_R4, IRE_R5),
        IRE_OP_OR(IRE_RF, IRE_R10)
    };

    int i;

    for (i = 0; i < (sizeof(tmp_code) / 2); ++i) {
        printf("%04x\n", tmp_code[i]);
    }

    error = ire_data_create(0x1000, 0, 0, NULL, &data);

    if (error != IRE_OK) {
        printf("ERROR: %x @ %d\n", (unsigned int)error, __LINE__);

        return EXIT_FAILURE;
    }

    error = ire_code_create(0x2800, 0x2800, 0x8000, 0x2000, 0, NULL, sizeof(tmp_code), (uint8_t*)tmp_code, &code);

    if (error != IRE_OK) {
        printf("ERROR: %x @ %d\n", (unsigned int)error, __LINE__);

        ire_data_destroy(&data);

        return EXIT_FAILURE;
    }

    error = ire_binary_create(data, code, &binary);

    if (error != IRE_OK) {
        printf("ERROR: %x @ %d\n", (unsigned int)error, __LINE__);

        ire_data_destroy(&data);
        ire_code_destroy(&code);

        return EXIT_FAILURE;
    }

    stream = fopen("test.ire", "wb");

    if (stream == NULL) {
        printf("ERROR: fopen @ %d\n", __LINE__);

        ire_binary_destroy(&binary);

        return EXIT_FAILURE;
    }

    error = ire_binary_write_to_file(binary, stream);

    if (error != IRE_OK) {
        printf("ERROR: %x @ %d\n", (unsigned int)error, __LINE__);

        fclose(stream);

        ire_binary_destroy(&binary);

        return EXIT_FAILURE;
    }

    fclose(stream);

    ire_binary_destroy(&binary);

    stream = fopen("test.ire", "rb");

    if (stream == NULL) {
        printf("ERROR: fopen @ %d\n", __LINE__);

        return EXIT_FAILURE;
    }

    error = ire_binary_create_from_file(stream, &binary);

    if (error != IRE_OK) {
        printf("ERROR: %x @ %d\n", (unsigned int)error, __LINE__);

        fclose(stream);

        return EXIT_FAILURE;
    }

    printf("loaded\n");

    uint16_t *test = (uint16_t*)(binary->code->data);

    for (i = 0; i < (binary->code->size / 2); ++i) {
        printf("%04x\n", test[i]);
    }

    ire_binary_destroy(&binary);

    fclose(stream);

    return EXIT_SUCCESS;
}
