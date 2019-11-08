#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "memory.h"

Memory::Memory(std::vector<unsigned char> byte){

  for (int i=0; i < byte.size(); i = i + 4){
    uint32_t tmp = byte[i+3] | byte[i+2] << 8 | byte[i+1] << 16 | byte[i] << 24;
    imem.push_back(tmp);
  }


  dmem.resize(dmem_length);
  reg.resize(32);

  reg[1] = 0xFFFFFFFF;
  reg[2] = 64;
  reg[8] = 0x10000000;

}

int Memory::iconvert(uint32_t input){
  std::cerr << "input: " << input << ", offset: " << imem_off + imem_length << '\n';
    if ((input < imem_off) || (input > imem_off + imem_length)){
      std::cerr << "Memmory Error" << '\n';
      std::exit(-10);
    }
    uint32_t offset  = input - imem_off;
    std::cerr << "final position: " << offset/4 << '\n';
    return offset/4;

}

int Memory::dconvert(uint32_t input){
  if ((input < dmem_off) || (input > dmem_off + dmem_length)){
    std::cerr << "Memmory Error" << '\n';
    std::exit(-10);
  }
  uint32_t offset  = input - dmem_off;
  return offset/4;
}

void Memory::showRegisters(){
  std::cerr << "******************************************" << '\n';
  for (int i = 0; i < reg.size(); i++){
    std::cerr << "Register " << i <<": " << +reg[i] << '\n';
  }
  std::cerr << "******************************************" << '\n';
}
