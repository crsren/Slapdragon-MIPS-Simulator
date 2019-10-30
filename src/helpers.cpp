#include <cstdint>

#include "helpers.h"

uint8_t bitwise::isolate8(uint32_t word, uint32_t start, uint32_t length) {
    uint8_t mask = ((1 << length) - 1) << start;
    return word & mask;

}

uint32_t bitwise::isolate32(uint32_t word, uint32_t start, uint32_t length) {
    uint32_t mask = ((1 << length) - 1) << start;
    return word & mask;

}
