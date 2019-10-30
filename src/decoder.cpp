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
        //  initiate r with input word
    } else if (opCode == 2 || opCode == 3) {
        tag = instruction::JTYPE;
    } else {
        tag = instruction::ITYPE;
    }
}

std::string instruction::content() {
    switch(tag) {
        case instruction::RTYPE: return "rrrrrrr";
        case instruction::JTYPE: return "jjjjjjj";
        case instruction::ITYPE: return "iiiiiii";
    }
}

void Rtype::init(uint32_t& word) {
    source1 = bitwise::isolate8(word,5,5);
    source2 = bitwise::isolate8(word,10,5);
    dest = bitwise::isolate8(word, 15,5);
    shift_amt = bitwise::isolate8(word, 20,5);
    fnCode = bitwise::isolate8(word, 26,5);
}
/*
void Itype::init(uint32_t& word) {
    source1 = bitwise::isolate8(word,5,5);
    source2 = bitwise::isolate8(word,10,5);
    address = bitwise::isolate32(word, 15,16);
}

void Jtype::init(uint32_t& word) {
    address = bitwise::isolate32(word,5,26);
} */
