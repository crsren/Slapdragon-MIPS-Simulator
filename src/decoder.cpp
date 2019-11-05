#include <string>
#include <cstdint>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>


#include "decoder.h"
#include "helpers.h"

instruction::instruction(uint32_t& word) {
    opCode = bitwise::isolate8(word, 0, 6);
    if (opCode == 0) {
        tag = instruction::RTYPE;
        r.init(word);
        //std::cout << "fnMap at 10: " << r.fnMap[10] << std::endl;
        //r.fnMap[r.fnCode];
    } else if (opCode == 2 || opCode == 3) {
        tag = instruction::JTYPE;
        j.init(word);
    } else {
        tag = instruction::ITYPE;
        i.init(word);
    }
}

void instruction::showContent() {
    switch(tag) {
        case instruction::RTYPE:
        std::cout << "[Source1: " << unsigned(r.source1) << " | Source2: " << unsigned(r.source2) << " | Dest: " << unsigned(r.dest) << " | Shift Amt: " << unsigned(r.shift_amt) << " | Fn Code: " << unsigned(r.fnCode) << " ]" << std::endl;
        break;

        case instruction::ITYPE: std::cout << "[OpCode: " << unsigned(opCode) <<" | Source1: " << unsigned(i.source1) << " | Source2/Dest:" << unsigned(i.source2) << " | Address: " << unsigned(i.address) << " ]" << std::endl;
        break;

        case instruction::JTYPE: std::cout << "[OpCode: " << unsigned(opCode) << " | Address:" << unsigned(j.address) << " ]" << std::endl;
        break;
    };
}

void Rtype::init(uint32_t& word) {
    source1 = bitwise::isolate8(word,7,5);
    source2 = bitwise::isolate8(word,12,5);
    dest = bitwise::isolate8(word, 17,5);
    shift_amt = bitwise::isolate8(word, 22,5);
    fnCode = bitwise::isolate8(word, 27,5);

    //since "non-const static data member must be initialized out of line"
    //fnMap[10] = 100;
}

void Itype::init(uint32_t& word) {
    source1 = bitwise::isolate8(word,5,5);
    source2 = bitwise::isolate8(word,10,5);
    address = bitwise::isolate32(word, 15,16);
}

void Jtype::init(uint32_t& word) {
    address = bitwise::isolate32(word,5,26);
}

// --------------------------------------------------------------------
// R-TYPE
void Rtype::ADDU(std::vector<uint32_t> &registers) {
    registers[dest] = registers[source1] + registers[source2];
}

void Rtype::JR(uint32_t& pc, const std::vector<uint32_t> &registers) {
     pc = memhelp::iconvert(registers[source1]);
}


//I-TYPE
void Itype::ADDI(std::vector<uint32_t> &registers){

}

void Rtype::test(int in){
  std::cerr << "Rtype test with input: " << in << '\n';
}
