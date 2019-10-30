#ifndef HELPERS_H
#define HELPERS_H

#include <cstdint>

struct bitwise {
    static uint8_t isolate8(uint32_t word, uint32_t start, uint32_t length);
    static uint32_t isolate32(uint32_t word, uint32_t start, uint32_t length);

};

#endif
