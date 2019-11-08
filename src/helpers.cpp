#include "helpers.h"
#include <cstdint>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>



const int imem_off = 0x1000000;
const int imem_length = 0x1000000;

const int dmem_off = 0x20000000;
const int dmem_length = 0x4000000;


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

int memhelp::iconvert(uint32_t input){
  std::cerr << "input: " << input << ", offset: " << imem_off + imem_length << '\n';
    if ((input < imem_off) || (input > imem_off + imem_length)){
      std::cerr << "Memmory Error" << '\n';
      std::exit(-10);
    }
    uint32_t offset  = input - imem_off;
    std::cerr << "final position: " << offset/4 << '\n';
    return offset/4;

}

int memhelp::dconvert(uint32_t input){
  if ((input < dmem_off) || (input > dmem_off + dmem_length)){
    std::cerr << "Memmory Error" << '\n';
    std::exit(-10);
  }
  uint32_t offset  = input - dmem_off;
  return offset/4;
}

void memhelp::showregisters(std::vector<uint32_t> reg){
  std::cerr << "******************************************" << '\n';
  for (int i = 0; i < reg.size(); i++){
    std::cerr << "Register " << i <<": " << +reg[i] << '\n';
  }
  std::cerr << "******************************************" << '\n';
}
