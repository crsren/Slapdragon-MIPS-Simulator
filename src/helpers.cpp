#include <cstdint>

#include "helpers.h"

uint8_t bitwise::isolate8(uint32_t word, int start, int length) {
    uint8_t mask = ((1 << length) - 1) << start;
    return word & mask;

}
