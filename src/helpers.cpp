#include "helpers.h"
#include <cstdint>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>


uint32_t bitwise::isolate(uint32_t word, uint32_t start, uint32_t length) {
    uint32_t temp = ((((1 << length) - 1) << start) & word) >> start;
    return temp;
}

std::string bitwise::get_binary(uint32_t word) {
    std::bitset<32> x(word);
    return x.to_string();
}

std::string bitwise::get_binary(uint8_t word) {
    std::bitset<8> x(word);
    return x.to_string();
}
