#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "memory.h"
#include "helpers.h"

Memory::Memory(std::vector<uint8_t> byte){

    for (int i=0; i < byte.size(); i = i + 4){
        uint32_t tmp = byte[i+3] | byte[i+2] << 8 | byte[i+1] << 16 | byte[i] << 24;
        imem.push_back(tmp);
    }

    dmem.resize(dmem_length);
    reg.resize(32);
}

Memory::Memory() {
    //for testing, initiating empty memory;
}

void Memory::branch(uint8_t target) {
    pc = ahead_pc;
    ahead_pc = execconvert(reg[target]);
}

void Memory::forward() {
    pc = ahead_pc;
    ahead_pc ++;
}

unsigned int Memory::readconvert(std::string& type, uint32_t input){
    std::cerr << "input: " << input << ", offset: " << imem_off + imem_length << '\n';
    if ((input >= imem_off) && (input <= imem_off + imem_length)){
        uint32_t offset  = input - imem_off;
        std::cerr << "final position: " << offset/4 << '\n';
        type = "imem";
        return offset/4;
    } else if ((input >= dmem_off) && (input <= dmem_off + dmem_length)){
        uint32_t offset  = input - dmem_off;
        std::cerr << "final position: " << offset/4 << '\n';
        type = "dmem";
        return offset/4;
    } else if (input == getc_off){
        char tmp;
        std::cin >> tmp;
        type = "getc";
        return (unsigned int)tmp;
    } else{
      std::cerr << "Memmory Error" << '\n';
      std::exit(-10);
    }
}

unsigned int Memory::writeconvert(std::string& type, uint32_t input){
  std::cerr << "input: " << input << ", offset: " << imem_off + imem_length << '\n';
  if ((input >= dmem_off) && (input <= dmem_off + dmem_length)){
      uint32_t offset  = input - dmem_off;
      std::cerr << "final position: " << offset/4 << '\n';
      type = "dmem";
      return offset/4;
  } else if (input == putc_off){
      char tmp;
      std::cout << tmp;
      type = "putc";
      return (unsigned int)tmp;
  } else{
    std::cerr << "Memmory Error" << '\n';
    std::exit(-10);
  }
}

unsigned int Memory::execconvert(uint32_t input){
    if (input == null_off){
      return -1;
    } else if ((input >= imem_off) && (input <= imem_off + imem_length)){
        uint32_t offset  = input - imem_off;
        std::cerr << "final position: " << offset/4 << '\n';
        return offset/4;
    } else{
      std::cerr << "Memmory Error" << '\n';
      std::exit(-10);
    }
}

void Memory::showRegisters(){
    std::cerr << "******************************************" << '\n';
    for (int i = 0; i < reg.size(); i++){
        std::cerr << "Register " << i <<": " << +reg[i] << '\n';
    }
    std::cerr << "******************************************" << '\n';
}
