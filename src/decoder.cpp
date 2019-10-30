#include <string>
#include <iostream>


#include "decoder.h"

instruction::instruction(char in) {
    if (in == 'r') { //later if opcode == 0 etc
        tag = instruction::RTYPE;
        //  initiate r with input word
    } else if (in == 'j') {
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
