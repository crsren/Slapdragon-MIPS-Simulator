#include <string>
#include <cstdint>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>


#include "decoder.h"
#include "helpers.h"
#include "memory.h"

void instruction::init(uint32_t& word) {
    opCode = bitwise::isolate(word, 0, 6);
    if (opCode == 0) {
        tag = 'R';
        r.init(word);
        //run = &r.fnMap[r.fnCode];

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

void instruction::run(uint32_t& pc, std::vector<uint32_t> &reg) {
    switch(tag) {
        case 'R':
        r.run(pc, reg);
        break;

        case 'I':

        break;

        case 'J':

        break;
    }
}

//-------------------------------------------------

void Rtype::init(uint32_t& word) {
    source1 = bitwise::isolate(word,6,5);
    source2 = bitwise::isolate(word,11,5);
    dest = bitwise::isolate(word, 16,5);
    shift_amt = bitwise::isolate(word, 21,5);
    fnCode = bitwise::isolate(word, 26,6);

    //since "non-const static data member must be initialized out of line"
    //fnMap[0b00100001] = ADDU;
}

void Rtype::run(uint32_t& pc, std::vector<uint32_t> &reg) {
    switch(fnCode) {
        case 0x00:
        //SLL(pc, reg);
        break;

        case 0x02:
        //SRL(pc, reg);
        break;

        case 0x03:
        //SRA(pc, reg);
        break;

        case 0x08:  //0b00100001:
        JR(pc, reg);
        break;

        case 0x10:  //0b00100001:
        //MFHI(pc, reg);
        break;

        case 0x11:  //0b00100001:
        //MTHI(pc, reg);
        break;

        case 0x12:  //0b00100001:
        //MFLO(pc, reg);
        break;

        case 0x13:  //0b00100001:
        //MTLO(pc, reg);
        break;

        case 0x18:  //0b00100001:
        //MULT(pc, reg);
        break;

        case 0x19:  //0b00100001:
        //MULTU(pc, reg);
        break;

        case 0x1A:  //0b00100001:
        //DIV(pc, reg);
        break;

        case 0x1B:  //0b00100001:
        //DIVU(pc, reg);
        break;

        case 0x20:
        ADD(pc, reg);
        break;

        case 0x21:  //0b00100001:
        ADDU(pc, reg);
        break;

        case 0x22:  //0b00100001:
        //SUB(pc, reg);
        break;

        case 0x23:  //0b00100001:
        //SUBU(pc, reg);
        break;

        case 0x24:  //0b00100001:
        //AND(pc, reg);
        break;

        case 0x25:  //0b00100001:
        //OR(pc, reg);
        break;

        case 0x26:  //0b00100001:
        //XOR(pc, reg);
        break;

        case 0x27:  //0b00100001:
        //NOR(pc, reg);
        break;

        case 0x2A:  //0b00100001:
        //SLT(pc, reg);
        break;

        case 0x2B:  //0b00100001:
        //SLTU(pc, reg);
        break;

    }
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
void Rtype::ADDU(uint32_t& pc, std::vector<uint32_t> &reg) {
    reg[dest] = reg[source1] + reg[source2];
    std::cout << " I do yoga at 4:30 am." << std::endl;
    pc++;
}

<<<<<<< HEAD
void Rtype::JR(uint32_t& pc, std::vector<uint32_t> &registers) {
    //pc = Memory::iconvert(registers[source1]);
=======
void Rtype::JR(uint32_t& pc, std::vector<uint32_t> &reg) {
    pc = memhelp::iconvert(reg[source1]);
>>>>>>> ba2cab210d854d2695cebd59074208c734de80de
    std::cout << " I read the bible a lot." << std::endl;
}

void Rtype::ADD(uint32_t& pc, std::vector<uint32_t> &reg) {
    int32_t s1 = (int32_t) reg[source1];
    int32_t s2 = (int32_t) reg[source2];
    if (((s1 + s2) < 0) && ((s1 > 0) && (s2 > 0)) || ((s1 + s2) > 0) && ((s1 < 0) && (s2 < 0))){
        std::cerr << "Overflow" << '\n';
        std::exit(-10);
    }
    reg[dest] = (uint32_t) (s1 + s2);
    std::cout << " ADD successfull" << std::endl;
    pc++;
}

//I-TYPE
void Itype::ADDI(uint32_t& pc, std::vector<uint32_t> &reg){

}
