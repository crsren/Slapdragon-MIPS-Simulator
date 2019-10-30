#include <string>
#include <iostream>


#include "decoder.h"

void instruction::instruction(char in) {
    if (in == 'r') { //later if opcode == 0 etc
        type = instruction::RTYPE;
        r =
    } else if (in == 'j') {
        type = instruction::JTYPE;
    } else {
        type = instruction::ITYPE;
    }
}

std::string instruction::content() {
    switch(type) {
        case instruction::r: std::cout << "rrrrrrr" << std::endl;
        case instruction::j: std::cout << "jjjjjjj" << std::endl;
        case instruction::i: std::cout << "iiiiiii" << std::endl;
    }
}
