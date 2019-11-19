#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "cpu.h"
#include "helpers.h"

Memory::Memory(std::vector<uint8_t> byte){
    imem = byte;
	  reg.resize(32);
    dmem.resize(dmem_length);
}

Memory::Memory() {
    //for testing, initiating empty memory;
}

uint32_t Memory::sign_extend(uint32_t word, int msb) {
        uint32_t extension = -(word >> msb) << (msb+1);
        return extension | word;
}

void Memory::branch(uint32_t target) {
    reg[0] = 0;
    pc = ahead_pc;
    ahead_pc = execConvert(target);
}

void Memory::forward() {
    reg[0] = 0;
    pc = ahead_pc;
    ahead_pc = ahead_pc + 4;
}

unsigned int Memory::readConvert(std::string& type, uint32_t input){
    std::cerr << "input: " << input << ", offset: " << imem_off + imem_length << '\n';
    if ((input >= imem_off) && (input <= imem_off + imem_length)){
        uint32_t offset  = input - imem_off;
        std::cerr << "final position: " << offset << '\n';
        type = "imem";
        return offset;
    } else if ((input >= dmem_off) && (input <= dmem_off + dmem_length)){
        uint32_t offset  = input - dmem_off;
        std::cerr << "final position: " << offset << '\n';
        type = "dmem";
        return offset;
    } else if (input == getc_off){
        char tmp;
        std::cin >> tmp;
        type = "getc";
        return (unsigned int)tmp;
    } else{
      std::cerr << "Memmory Error" << '\n';
      std::exit(-11);
    }
}

unsigned int Memory::writeConvert(std::string& type, uint32_t input){
  std::cerr << "input: " << input << ", offset: " << imem_off + imem_length << '\n';
  if ((input >= dmem_off) && (input <= dmem_off + dmem_length)){
      uint32_t offset  = input - dmem_off;
      std::cerr << "final position: " << offset << '\n';
      type = "dmem";
      return offset;
  } else if (input == putc_off){
      type = "putc";
      return 0;
  } else{
    std::cerr << "Memmory Error" << '\n';
    std::exit(-11);
  }
}

unsigned int Memory::execConvert(uint32_t input){
    if (input == null_off){
      return -1;
    } else if ((input >= imem_off) && (input <= imem_off + imem_length)){
        uint32_t offset  = input - imem_off;
        std::cerr << "final position: " << offset << '\n';
        return offset;
    } else{
      std::cerr << "Memmory Error" << '\n';
      std::exit(-11);
    }
}

uint32_t Memory::instrToWord(int start){
    if (start % 4 != 0){
      std::cerr << "Non alligned address" << '\n';
      exit(-1);
    }
    uint32_t tmp = imem[start+3] | imem[start+2] << 8 | imem[start+1] << 16 | imem[start] << 24;
    return tmp;
}

uint32_t Memory::dataToWord(int start){
    if (start % 4 != 0){
      std::cerr << "Non alligned address" << '\n';
      exit(-1);
    }
    uint32_t tmp = dmem[start+3] | dmem[start+2] << 8 | dmem[start+1] << 16 | dmem[start] << 24;
    return tmp;
}

void Memory::showRegisters(){
    std::cerr << "******************************************" << '\n';
    for (unsigned int i = 0; i < reg.size(); i++){
        std::cerr << "Register " << i <<": " << +reg[i] << '\n';
    }
    std::cerr << "******************************************" << '\n';
}
