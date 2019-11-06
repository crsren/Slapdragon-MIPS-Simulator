#include <string>
#include <cstdint>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>


#include "decoder.h"
#include "helpers.h"

void instruction::init(uint32_t& word) {
    opCode = bitwise::isolate(word, 0, 6);
    if (opCode == 0) {
        tag = 'R';
        r.init(word);
        run = r.fnMap[r.fnCode];
    } else if (opCode == 2 || opCode == 3) {
        tag = 'I';
        j.init(word);
    } else {
        tag = 'J';
        i.init(word);
    }
}

void instruction::showContent() {
    switch(tag) {
        case 'R':
        std::cout << "[Source1: " << bitwise::get_binary(r.source1) << " | Source2: " << bitwise::get_binary(r.source2) << " | Dest: " << bitwise::get_binary(r.dest) << " | Shift Amt: " << bitwise::get_binary(r.shift_amt) << " | Fn Code: " << bitwise::get_binary(r.fnCode) << " ]" << std::endl;
        break;

        case 'I': std::cout << "[OpCode: " << bitwise::get_binary(opCode) <<" | Source1: " << bitwise::get_binary(i.source1) << " | Source2/Dest:" << bitwise::get_binary(i.source2) << " | Address: " << bitwise::get_binary(i.address) << " ]" << std::endl;
        break;

        case 'J': std::cout << "[OpCode: " << bitwise::get_binary(opCode) << " | Address:" << bitwise::get_binary(j.address) << " ]" << std::endl;
        break;
    };
}

void Rtype::init(uint32_t& word) {
    source1 = bitwise::isolate(word,6,5);
    source2 = bitwise::isolate(word,11,5);
    dest = bitwise::isolate(word, 16,5);
    shift_amt = bitwise::isolate(word, 21,5);
    fnCode = bitwise::isolate(word, 26,6);

    //since "non-const static data member must be initialized out of line"
    fnMap[0b00000000] = test1;
    fnMap[0b00111111] = test2;
}

void Itype::init(uint32_t& word) {
    source1 = bitwise::isolate(word,5,5);
    source2 = bitwise::isolate(word,10,5);
    address = bitwise::isolate(word, 15,16);
}

void Jtype::init(uint32_t& word) {
    address = bitwise::isolate(word,5,26);
}

// --------------------------------------------------------------------
// R-TYPE
void Rtype::ADDU(std::vector<uint32_t> &registers) {
    registers[dest] = registers[source1] + registers[source2];
}

void Rtype::JR(uint32_t& pc, const std::vector<uint32_t> &registers) {
     pc = memhelp::iconvert(registers[source1]);
}

void Rtype::test1(int in){
  std::cerr << "Test 1 baby: " << in << '\n';
}

void Rtype::test2(int in){
  std::cerr << "Test 2 baby: " << in << '\n';
}

//I-TYPE
void Itype::ADDI(std::vector<uint32_t> &registers){

}
