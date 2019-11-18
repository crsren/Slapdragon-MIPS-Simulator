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
        std::cerr << "Rtype instruction" << std::endl;
        r.init(word);
        //run = &r.fnMap[r.fnCode];

    } else if (opCode == 2 || opCode == 3) {
        tag = 'J';
        std::cerr << "Jtype instruction" << std::endl;
        j.init(word);
    } else {
        tag = 'I';
        std::cerr << "Itype instruction" << std::endl;
        i.init(word);
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

    //fnMap[0b00100001] = ADDU;
}

void Rtype::run(Memory& mem) {
    switch(fnCode) {
        case 0x00:
        SLL(mem);
        std::cerr << "SLL" << '\n';
        break;

        case 0x02:
        SRL(mem);
        std::cerr << "SRL" << '\n';
        break;

        case 0x03:
        SRA(mem);
        std::cerr << "SRA" << '\n';
        break;

        case 0x08:  //0b00100001:
        JR(mem);
        std::cerr << "JR" << '\n';
        break;

        case 0x10:  //0b00100001:
        MFHI(mem);
        std::cerr << "MFHI" << '\n';
        break;

        case 0x11:  //0b00100001:
        MTHI(mem);
        std::cerr << "MTHI" << std::endl;
        exit(-1);
        break;

        case 0x12:  //0b00100001:
        MFLO(mem);
        std::cerr << "MFLO" << std::endl;
        exit(-1);
        break;

        case 0x13:  //0b00100001:
        MTLO(mem);
        std::cerr << "MTLO" << std::endl;
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
        std::cerr << "ADD" << '\n';
        break;

        case 0x21:  //0b00100001:
        ADDU(mem);
        std::cerr << "ADDU" << '\n';
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


        default:
        std::cerr << "Non-existing instruction." << '\n';
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
        std::cerr << "ADDI" << '\n';
        break;

        case 0x0D:
        ORI(mem);
        std::cerr << "ORI" << '\n';
        break;

        case 0x0F:
        LUI(mem);
        std::cerr << "LUI" << '\n';
        break;

        case 0x23:
        std::cerr << "LW" << '\n';
        LW(mem);
        break;

        default:
        std::cerr << "Non-existing instruction." << '\n';
        exit(-1);
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
void Rtype::SLL(Memory& mem) {
    mem.reg[dest] = mem.reg[source2] << shift_amt;
    mem.forward();
}

void Rtype::SRL(Memory& mem) {
    mem.reg[dest] = mem.reg[source2] >> shift_amt;
    mem.forward();
}

void Rtype::SRA(Memory& mem) {
    uint32_t bottom = mem.reg[source2] >> shift_amt;
    uint32_t top = -(mem.reg[source2] >> 31) << (32-shift_amt);
    mem.reg[dest] = top | bottom;

    mem.forward();
}

void Rtype::JR(Memory& mem) {
    mem.branch(source1);
}

void Rtype::MFHI(Memory& mem) {
    mem.reg[dest] = mem.hi;
    mem.forward();
}

void Rtype::MTHI(Memory& mem) {
    mem.hi = mem.reg[source1];
    mem.forward();
}

void Rtype::MFLO(Memory& mem) {
    mem.reg[dest] = mem.lo;
    mem.forward();
}

void Rtype::MTLO(Memory& mem) {
    mem.lo = mem.reg[source1];
    mem.forward();
}

void Rtype::MULT(Memory& mem){
  int s1 = (int) mem.reg[source1];
  int s2 = (int) mem.reg[source2];
  long int tmp = s1 * s2;
  //mem.lo = bitwise::isolate()
  mem.forward();
}

void Rtype::ADD(Memory& mem) {
    int s1 = (int) mem.reg[source1];
    int s2 = (int) mem.reg[source2];
    if ( ( ((s1 + s2) < 0) && ((s1 > 0) && (s2 > 0)) ) || ( ((s1 + s2) > 0) && ((s1 < 0) && (s2 < 0)) ) ){
        std::cerr << "Overflow" << '\n';
        exit(-10);
    }
    mem.reg[dest] = (uint32_t) (s1 + s2);
    mem.forward();
}

void Rtype::ADDU(Memory& mem) {
    mem.reg[dest] = mem.reg[source1] + mem.reg[source2];
    mem.forward();
}

void Rtype::AND(Memory& mem) {

}
//----------------------------------------------------------
//I-TYPE
void Itype::ADDI(Memory& mem){

    /* thinking maybe like this?
    if(!int_overflow(a,b) ) {
        mem.reg[source2] = mem.reg[source1] + immediate;
    }
    */

    std::cerr << "not fully implemented." << '\n';
}

void Itype::LUI(Memory& mem){
    uint32_t tmp  = immediate << 16;
    mem.reg[source2] = tmp;
    mem.forward();
}

void Itype::ORI(Memory& mem){
    mem.reg[source2] = mem.reg[source1] | immediate;
    mem.forward();
}

void Itype::LW(Memory& mem){
    uint32_t location = mem.reg[source2] + (int)immediate;
    if (location % 4 != 0){
      std::cerr << "Address Error, not alligned address" << '\n';
      exit(-11);
    }
    std::string type = "";
    unsigned int value = mem.readconvert(type, location);
    if (type == "imem"){
      mem.reg[source1] = (int)mem.instrtoword(value);
    } else if (type == "dmem"){
      mem.reg[source1] = (int)mem.datatoword(value);
    } else if (type == "getc"){
      mem.reg[source1] = value;
    }
    mem.forward();
}

void Itype::LWL(Memory& mem){
    unsigned int location = mem.reg[source2] + (int)immediate;

    std::string type = "";
    unsigned int value = mem.readconvert(type, location);

    if (type == "imem"){
      int tmp = (int)mem.instrtoword(value);
      mem.reg[source1] = bitwise::isolate(tmp, 15, 16);
    } else if (type == "dmem"){
      int tmp = (int)mem.datatoword(value);
      mem.reg[source1] = bitwise::isolate(tmp, 15, 16);
    } else if (type == "getc"){
      int tmp = value;
      mem.reg[source1] = bitwise::isolate(tmp, 15, 16);
    }
    mem.forward();
}

void Itype::LWR(Memory& mem){ //doesnt properly work, needs to be sign extended
    unsigned int location = mem.reg[source2] + (int)immediate;

    std::string type = "";
    unsigned int value = mem.readconvert(type, location);

    if (type == "imem"){
      int tmp = (int)mem.instrtoword(value);
      mem.reg[source1] = bitwise::isolate(tmp, 0, 16);
    } else if (type == "dmem"){
      int tmp = (int)mem.datatoword(value);
      mem.reg[source1] = bitwise::isolate(tmp, 0, 16);
    } else if (type == "getc"){
      int tmp = value;
      mem.reg[source1] = bitwise::isolate(tmp, 0, 16);
    }
    mem.forward();
}
