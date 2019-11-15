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
    opCode = bitwise::isolate(word, 26, 6);
    if (opCode == 0) {
        tag = 'R';
        r.init(word);
        //run = &r.fnMap[r.fnCode];
        std::cerr << "Rtype instruction" << std::endl;

    } else if (opCode == 2 || opCode == 3) {
        tag = 'J';
        j.init(word);
    } else {
        tag = 'I';
        i.init(word);
        std::cerr << "Jtype instruction" << std::endl;
    }
}

void instruction::showContent() {
    switch(tag) {
        case 'R':
        std::cerr << "[Source1: " << bitwise::get_binary(r.source1) << " | Source2: " << bitwise::get_binary(r.source2) << " | Dest: " << bitwise::get_binary(r.dest) << " | Shift Amt: " << bitwise::get_binary(r.shift_amt) << " | Fn Code: " << bitwise::get_binary(r.fnCode) << " ]" << std::endl;
        break;

        case 'I': std::cerr << "[OpCode: " << bitwise::get_binary(opCode) <<" | Source1: " << bitwise::get_binary(i.source1) << " | Source2/Dest:" << bitwise::get_binary(i.source2) << " | immediate: " << bitwise::get_binary(i.immediate) << " ]" << std::endl;
        break;

        case 'J': std::cerr << "[OpCode: " << bitwise::get_binary(opCode) << " | Address:" << bitwise::get_binary(j.address) << " ]" << std::endl;
        break;
    };
}

void instruction::run(Memory& mem) {
    switch(tag) {
        case 'R':
        r.run(mem);
        break;

        case 'I':
        i.run(mem);
        break;

        case 'J':
        j.run(mem);
        break;
    }
}

//-------------------------------------------------

void Rtype::init(uint32_t& word) {
    source1 = bitwise::isolate(word,21,5);
    source2 = bitwise::isolate(word,16,5);
    dest = bitwise::isolate(word, 11,5);
    shift_amt = bitwise::isolate(word, 6,5);
    fnCode = bitwise::isolate(word, 0,6);

    //since "non-const static data member must be initialized out of line"
    //fnMap[0b00100001] = ADDU;
}

void Rtype::run(Memory& mem) {
    switch(fnCode) {
        case 0x00:
        //SLL(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x02:
        //SRL(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x03:
        //SRA(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x08:  //0b00100001:
        JR(mem);
        break;

        case 0x10:  //0b00100001:
        MFHI(mem);
        break;

        case 0x11:  //0b00100001:
        //MTHI(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x12:  //0b00100001:
        //MFLO(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x13:  //0b00100001:
        //MTLO(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x18:  //0b00100001:
        //MULT(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x19:  //0b00100001:
        //MULTU(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x1A:  //0b00100001:
        //DIV(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x1B:  //0b00100001:
        //DIVU(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x20:
        ADD(mem);
        break;

        case 0x21:  //0b00100001:
        ADDU(mem);
        break;

        case 0x22:  //0b00100001:
        //SUB(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x23:  //0b00100001:
        //SUBU(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x24:  //0b00100001:
        //AND(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x25:  //0b00100001:
        //OR(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x26:  //0b00100001:
        //XOR(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x27:  //0b00100001:
        //NOR(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x2A:  //0b00100001:
        //SLT(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

        case 0x2B:  //0b00100001:
        //SLTU(mem);
        std::cerr << "Not implemented yet." << std::endl;
        exit(-1);
        break;

    }
}

void Itype::init(uint32_t& word) {
    opCode = bitwise::isolate(word, 26, 6);
    source1 = bitwise::isolate(word,21,5);
    source2 = bitwise::isolate(word,16,5);
    immediate = bitwise::isolate(word, 0,16);
}

void Itype::run(Memory& mem) {
  switch(opCode) {
    case 0x08:
    ADDI(mem);
    break;

    case 0x0F:
    LUI(mem);
    break;

    case 0x0D:
    ORI(mem);
    break;


  }
}



void Jtype::init(uint32_t& word) {
    address = bitwise::isolate(word,0,26);
}

void Jtype::run(Memory& mem) {
    std::cerr << "J.run not implemented yet." << '\n';
    exit(-1);
}

// --------------------------------------------------------------------
// R-TYPE
void Rtype::ADDU(Memory& mem) {
    mem.reg[dest] = mem.reg[source1] + mem.reg[source2];
    mem.pc = mem.ahead_pc;
    mem.ahead_pc++;
}

void Rtype::JR(Memory& mem) {
    mem.pc = mem.ahead_pc;
    mem.ahead_pc = mem.iconvert(mem.reg[source1]);

}

void Rtype::ADD(Memory& mem) {
    int32_t s1 = (int32_t) mem.reg[source1];
    int32_t s2 = (int32_t) mem.reg[source2];
    if ( ( ((s1 + s2) < 0) && ((s1 > 0) && (s2 > 0)) ) || ( ((s1 + s2) > 0) && ((s1 < 0) && (s2 < 0)) ) ){
        std::cerr << "Overflow" << '\n';
        std::exit(-10);
    }
    mem.reg[dest] = (uint32_t) (s1 + s2);
    std::cerr << " ADD successfull" << std::endl;
    mem.pc = mem.ahead_pc;
    mem.ahead_pc++;
}

void Rtype::MFHI(Memory& mem) {
    mem.reg[dest] = mem.hi;
    mem.pc = mem.ahead_pc;
    mem.ahead_pc++;
}
//I-TYPE
void Itype::ADDI(Memory& mem){

}

void Itype::LUI(Memory& mem){
  std::cerr << "LUI" << '\n';
  uint32_t tmp  = immediate << 16;
  mem.reg[source2] = tmp;
  mem.pc = mem.ahead_pc;
  mem.ahead_pc++;
}

void Itype::ORI(Memory& mem){
  std::cerr << "ORI" << '\n';
  mem.reg[source2] = mem.reg[source1] | immediate;
  mem.pc = mem.ahead_pc;
  mem.ahead_pc++;
}
