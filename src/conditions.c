#include "ire.h"


IRE_API(ire_error_t)
ire_conditions_check(uint8_t condition, ire_cpu_t *cpu) {
    uint16_t rc, rf;

    rc = cpu->registers[IRE_RC];
    rf = cpu->registers[IRE_RF];

    switch (condition) {
        case IRE_CONDITIONS_NONE:
            return IRE_OK;

        case IRE_CONDITIONS_EQUAL:
            return rc & (1 << 0) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_NOT_EQUAL:
            return !(rc & (1 << 0)) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_GREATER:
            return rc & (1 << 1) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_GREATER_EQUAL:
            return rc & (1 << 1) || rc & (1 << 0) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_LESS:
            return rc & (1 << 2) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_LESS_EQUAL:
            return rc & (1 << 2) || rc & (1 << 0) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_ABOVE:
            return rc & (1 << 3) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_ABOVE_EQUAL:
            return rc & (1 << 3) || rc & (1 << 0) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_BELOW:
            return rc & (1 << 4) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_BELOW_EQUAL:
            return rc & (1 << 4) || rc & (1 << 0) ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_FLAG_INTERRUPT:
            return rf & IRE_FLAGS_INTERRUPT ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_FLAG_OVERFLOW:
            return rf & IRE_FLAGS_OVERFLOW ? IRE_OK : IRE_EXIT;

        case IRE_CONDITIONS_FLAG_CARRY:
            return rf & IRE_FLAGS_CARRY ? IRE_OK : IRE_EXIT;
    }

    return IRE_EXIT;
}
