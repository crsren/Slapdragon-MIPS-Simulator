#include "helpers.h"
#include <cstdint>
#include <bitset>
#include <string>

const int imem_off = 0x10000000;
const int imem_length = 0x1000000;

const int dmem_off = 0x20000000;
const int dmem_length = 0x4000000;


uint8_t bitwise::isolate8(uint32_t word, uint32_t start, uint32_t length) {
    uint8_t temp = ((1 << length) - 1) << start;
    return word & temp;
}

uint32_t bitwise::isolate32(uint32_t word, uint32_t start, uint32_t length) {
    uint32_t temp = ((1 << length) - 1) << start;
    return word & temp;

}

std::string bitwise::get_binary(uint32_t word) {
    std::bitset<32> x(word);
    return x.to_string();
}

std::string bitwise::get_binary(uint8_t word) {
    std::bitset<8> x(word);
    return x.to_string();
}

int memhelp::iconvert(uint32_t input){
    if ((input < imem_off) || (input > imem_off + imem_length)){
      std::exit(-10);
    }
    uint32_t offset  = input - imem_off;
    return offset/4;

}

int memhelp::dconvert(uint32_t input){
  if ((input < dmem_off) || (input > dmem_off + dmem_length)){
    std::exit(-10);
  }
  uint32_t offset  = input - dmem_off;
  return offset/4;
}
