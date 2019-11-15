#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "memory.h"
#include "helpers.h"

Memory::Memory(std::vector<unsigned char> byte){

  for (int i=0; i < byte.size(); i = i + 4){
    unsigned int tmp = byte[i+3] | byte[i+2] << 8 | byte[i+1] << 16 | byte[i] << 24;
    imem.push_back(tmp);
  }


  dmem.resize(dmem_length);
  reg.resize(32);

}

int Memory::iconvert(unsigned int input){
  std::cerr << "input: " << input << ", offset: " << imem_off + imem_length << '\n';
    if (input == 0){
      return -1;
    }else if ((input < imem_off) || (input > imem_off + imem_length) ){
      std::cerr << "Memmory Error" << '\n';
      std::exit(-10);
    }
    unsigned int offset  = input - imem_off;
    std::cerr << "final position: " << offset/4 << '\n';
    return offset/4;

}

int Memory::dconvert(unsigned int input){
  if ( (input < dmem_off) || (input > dmem_off + dmem_length) || (bitwise::isolate(input, 2, 0) != 0 )){
    std::cerr << "Memmory Error" << '\n';
    std::exit(-10);
  }
  unsigned int offset  = input - dmem_off;
  return offset/4;
}

void Memory::showRegisters(){
  std::cerr << "******************************************" << '\n';
  for (int i = 0; i < reg.size(); i++){
    std::cerr << "Register " << i <<": " << +reg[i] << '\n';
  }
  std::cerr << "******************************************" << '\n';
}
