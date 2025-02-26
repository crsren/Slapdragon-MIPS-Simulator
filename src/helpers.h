#ifndef HELPERS_H
#define HELPERS_H

#include <cstdint>
#include <string>
#include <vector>


struct bitwise {
    static uint32_t isolate(uint32_t word, uint32_t start, uint32_t length);
    static std::string get_binary(uint32_t word);
    static std::string get_binary(uint8_t word);

};

#endif
