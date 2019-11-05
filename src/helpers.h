#ifndef HELPERS_H
#define HELPERS_H

#include <cstdint>
#include <string>

struct bitwise {
    static uint8_t isolate8(uint32_t word, uint32_t start, uint32_t length);
    static uint32_t isolate32(uint32_t word, uint32_t start, uint32_t length);
    static std::string get_binary(uint32_t word);
    static std::string get_binary(uint8_t word);

};

struct memhelp {
    static int iconvert(uint32_t input);
    static int dconvert(uint32_t input);
};

#endif
