#include "ire.h"


void usage(void);


void usage(void) {
    printf("usage: ire [file] [args]\n");
}


int main(int argc, char **argv) {
    ire_error_t error;
    ire_binary_t *binary;
    ire_cpu_t *cpu;
    uint16_t result;
    FILE *stream;

    if (argc == 1) {
        usage();

        return EXIT_SUCCESS;
    }

    stream = fopen(argv[1], "rb");

    if (stream == NULL) {
        printf("Error: can't open file %s\n", argv[1]);

        return EXIT_FAILURE;
    }

    error = ire_binary_create_from_file(stream, &binary);

    fclose(stream);

    if (error != IRE_OK) {
        printf("Error: invalid binary (%zd)\n", error);

        return EXIT_FAILURE;
    }

    error = ire_cpu_create(binary, &cpu);

    ire_binary_destroy(&binary);

    if (error != IRE_OK) {
        printf("Error: invalid binary (%zd)\n", error);

        return EXIT_FAILURE;
    }

    error = ire_cpu_run(cpu, &result);

    printf("%hu\n", result);

    ire_cpu_destroy(&cpu);

    return EXIT_SUCCESS;
}
