#include <string>
#include <iostream>


#include "decoder.h"
#include "helpers.h"

instruction::instruction(uint32_t& word) {
    opCode = bitwise::isolate8(word, 0, 6);
    std::cout << "opCode: " << unsigned(opCode) << std::endl;
    if (opCode == 0) {
        tag = instruction::RTYPE;
        r.init(word);
        std::cout << "issa rtype" << std::endl;
    } else if (opCode == 2 || opCode == 3) {
        tag = instruction::JTYPE;
        j.init(word);
        std::cout << "issa jtype" << std::endl;
    } else {
        tag = instruction::ITYPE;
        i.init(word);
        std::cout << "issa itype" << std::endl;
    }
    //content.init(word); if rji could have same name
}

// declare show functions inside rji classes instead if could have same name
void instruction::showContent() {
    switch(tag) {
        case instruction::RTYPE: std::cout << "[Source1: " << r.source1 << " | Source2:" << r.source2 << " | Dest: " << r.dest << " | Shift Amt: " << r.shift_amt << " | Fn Code: " << r.fnCode << " ]" << std::endl;

        case instruction::ITYPE: std::cout << "[OpCode: " << opCode <<" | Source1: " << i.source1 << " | Source2/Dest:" << i.source2 << " | Address: " << i.address << " ]" << std::endl;

        case instruction::JTYPE: std::cout << "[OpCode: " << opCode << " | Address:" << j.address << " ]" << std::endl;
    };
}

void Rtype::init(uint32_t& word) {
    source1 = bitwise::isolate8(word,5,5);
    source2 = bitwise::isolate8(word,10,5);
    dest = bitwise::isolate8(word, 15,5);
    shift_amt = bitwise::isolate8(word, 20,5);
    fnCode = bitwise::isolate8(word, 26,5);
}

void Itype::init(uint32_t& word) {
    source1 = bitwise::isolate8(word,5,5);
    source2 = bitwise::isolate8(word,10,5);
    address = bitwise::isolate32(word, 15,16);
}

void Jtype::init(uint32_t& word) {
    address = bitwise::isolate32(word,5,26);
}
