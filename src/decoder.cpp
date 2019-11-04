#include <string>
#include <iostream>


#include "decoder.h"
#include "helpers.h"

instruction::instruction(uint32_t& word) {
    opCode = bitwise::isolate8(word, 0, 6);
    if (opCode == 0) {
        tag = instruction::RTYPE;
        r.init(word);
    } else if (opCode == 2 || opCode == 3) {
        tag = instruction::JTYPE;
        j.init(word);
    } else {
        tag = instruction::ITYPE;
        i.init(word);
    }
    //content.init(word); if rji could have same name
}

// declare show functions inside rji classes instead if could have same name
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

// void Rtype::JR(uint32_t& pc) {
//     pc = registers[source1]
// }
