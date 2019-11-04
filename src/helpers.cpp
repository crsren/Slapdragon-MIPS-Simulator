#include "helpers.h"
#include <cstdint>
#include <bitset>
#include <string>

uint8_t bitwise::isolate8(uint32_t word, uint32_t start, uint32_t length) {

    return (((1 << length) - 1) & (word >> (start - 1)));

}

uint32_t bitwise::isolate32(uint32_t word, uint32_t start, uint32_t length) {
    uint32_t temp = ((1 << length) - 1) << start;
    return word & temp >> start;

}

std::string bitwise::get_binary(uint32_t word) {
    std::bitset<32> x(word);
    return x.to_string();
}

std::string bitwise::get_binary(uint8_t word) {
    std::bitset<8> x(word);
    return x.to_string();
}
