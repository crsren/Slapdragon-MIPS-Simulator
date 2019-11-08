#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>



void Memory::Memory(){

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

void Memory::showregisters(std::vector<uint32_t> reg){
  std::cerr << "******************************************" << '\n';
  for (int i = 0; i < reg.size(); i++){
    std::cerr << "Register " << i <<": " << +reg[i] << '\n';
  }
  std::cerr << "******************************************" << '\n';
}
