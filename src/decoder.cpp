#include <string>
#include <cstdint>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>


#include "decoder.h"
#include "helpers.h"
#include "cpu.h"

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
        j.init(word, opCode);
    } else {
        tag = 'I';
        std::cerr << "Itype instruction" << std::endl;
        i.init(word, opCode);
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

        case 0x04:
        SLLV(mem);
        std::cerr << "SLLV" << '\n';
        break;

        case 0x06:
        SRLV(mem);
        std::cerr << "SRLV" << '\n';
        break;

        case 0x07:
        SRAV(mem);
        std::cerr << "SRAV" << '\n';
        break;

        case 0x08:  //0b00100001:
        JR(mem);
        std::cerr << "JR" << '\n';
        break;

        case 0x09:
        JALR(mem);
        std::cerr << "JALR" << '\n';
        break;

        case 0x10:  //0b00100001:
        MFHI(mem);
        std::cerr << "MFHI" << '\n';
        break;

        case 0x11:  //0b00100001:
        MTHI(mem);
        std::cerr << "MTHI" << std::endl;
        break;

        case 0x12:  //0b00100001:
        MFLO(mem);
        std::cerr << "MFLO" << std::endl;
        break;

        case 0x13:  //0b00100001:
        MTLO(mem);
        std::cerr << "MTLO" << std::endl;
        break;

        case 0x18:  //0b00100001:
        MULT(mem);
        std::cerr << "MULT" << std::endl;
        break;

        case 0x19:  //0b00100001:
        MULTU(mem);
        std::cerr << "MULTU" << std::endl;
        break;

        case 0x1A:  //0b00100001:
        DIV(mem);
        break;

        case 0x1B:  //0b00100001:
        DIVU(mem);
        std::cerr << "DIVU" << '\n';
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
        SUB(mem);
        std::cerr << "SUB" << std::endl;
        break;

        case 0x23:  //0b00100001:
        SUBU(mem);
        std::cerr << "SUBU" << std::endl;
        break;

        case 0x24:  //0b00100001:
        AND(mem);
        break;

        case 0x25:  //0b00100001:
        OR(mem);
        std::cerr << "OR" << std::endl;
        break;

        case 0x26:  //0b00100001:
        XOR(mem);
        std::cerr << "XOR" << std::endl;
        break;

        case 0x2A:  //0b00100001:
        SLT(mem);

        break;

        case 0x2B:  //0b00100001:
        SLTU(mem);
        std::cerr << "SLTU" << std::endl;
        break;

        default:
        std::cerr << "Non-existing instruction." << '\n';
        exit(-12);
    }
}

void Itype::init(uint32_t& word, uint8_t& ins_op) {
    opCode = ins_op;
    source1 = bitwise::isolate(word,21,5);
    source2 = bitwise::isolate(word,16,5);
    immediate = bitwise::isolate(word, 0,16);
}

void Itype::run(Memory& mem) {
    switch(opCode) {
        case 0x01:
        switch(source2) {
            case 0x00:
            std::cerr << "BLTZ" << '\n';
            BLTZ(mem);
            break;

            case 0x01:
            std::cerr << "BGEZ" << '\n';
            BGEZ(mem);
            break;

            case 0x10:
            std::cerr << "BLTZAL" << '\n';
            BLTZAL(mem);
            break;

            case 0x11:
            std::cerr << "BGEZAL" << '\n';
            BGEZAL(mem);
            break;

            default:
            std::cerr << "Non-existing instruction." << '\n';
            exit(-12);
        }
        break;

        case 0x04:
        BEQ(mem);
        std::cerr << "BEQ" << '\n';
        break;

        case 0x05:
        BNE(mem);
        std::cerr << "BNE" << '\n';
        break;

        case 0x06:
        std::cerr << "BLEZ" << '\n';
        BLEZ(mem);
        break;

        case 0x07:
        std::cerr << "BGTZ" << '\n';
        BGTZ(mem);
        break;

        case 0x08:
        ADDI(mem);
        std::cerr << "ADDI" << '\n';
        break;

        case 0x09:
        ADDIU(mem);
        std::cerr << "ADDIU" << '\n';
        break;

        case 0x0A:
        SLTI(mem);
        std::cerr << "SLTI" << '\n';
        break;

        case 0x0B:
        SLTIU(mem);
        std::cerr << "SLTIU" << '\n';
        break;

        case 0x0C:
        ANDI(mem);
        std::cerr << "ANDI" << '\n';
        break;

        case 0x0D:
        ORI(mem);
        std::cerr << "ORI" << '\n';
        break;

        case 0x0E:
        XORI(mem);
        std::cerr << "XORI" << '\n';
        break;

        case 0x0F:
        LUI(mem);
        std::cerr << "LUI" << '\n';
        break;

        case 0x20:
        LB(mem);
        std::cerr << "LB" << '\n';
        break;

        case 0x21:
        LH(mem);
        std::cerr << "LH" << '\n';
        break;

        case 0x22:
        LWL(mem);
        std::cerr << "LWL" << '\n';
        break;

        case 0x23:
        std::cerr << "LW" << '\n';
        LW(mem);
        break;

        case 0x24:
        LBU(mem);
        std::cerr << "LBU" << '\n';
        break;

        case 0x25:
        LHU(mem);
        std::cerr << "LHU" << '\n';
        break;

        case 0x26:
        LWR(mem);
        std::cerr << "LWR" << '\n';
        break;

        case 0x28:
        SB(mem);
        std::cerr << "SB" << '\n';
        break;

        case 0x29:
        SH(mem);
        std::cerr << "SH" << '\n';
        break;

        case 0x2B:
        SW(mem);
        std::cerr << "SW" << '\n';
        break;

        default:
        std::cerr << "Non-existing instruction." << '\n';
        exit(-12);
    }
}



void Jtype::init(uint32_t& word, uint8_t& ins_op) {
    address = bitwise::isolate(word,0,26);
    opCode = ins_op;
}

void Jtype::run(Memory& mem) {
    switch(opCode) {
        case 0x02:
        std::cerr << "J" << '\n';
        J(mem);
        break;

        case 0x03:
        std::cerr << "JAL" << '\n';
        JAL(mem);
        break;

        default:
        std::cerr << "Non-existing instruction." << '\n';
        exit(-12);
    }
}

// --------------------------------------------------------------------
// R-TYPE
void Rtype::SLL(Memory& mem) {
    mem.forward();
    mem.reg[dest] = mem.reg[source2] << shift_amt;
}

void Rtype::SLLV(Memory& mem) {
    mem.forward();
    mem.reg[dest] = mem.reg[source2] << bitwise::isolate(mem.reg[source1], 0, 5);
}

void Rtype::SRL(Memory& mem) {
    mem.forward();
    mem.reg[dest] = mem.reg[source2] >> shift_amt;
}

void Rtype::SRLV(Memory& mem) {
    mem.forward();
    mem.reg[dest] = mem.reg[source2] >> bitwise::isolate(mem.reg[source1], 0, 5);
}

void Rtype::SRA(Memory& mem) {
    mem.forward();
    uint32_t bottom = mem.reg[source2] >> shift_amt;
    uint32_t top = -(mem.reg[source2] >> 31) << (32-shift_amt);
    mem.reg[dest] = top | bottom;
}

void Rtype::SRAV(Memory& mem) {
    mem.forward();
    uint32_t bottom = mem.reg[source2] >> bitwise::isolate(mem.reg[source1], 0, 5);
    uint32_t top = -(mem.reg[source2] >> 31) << (32-bitwise::isolate(mem.reg[source1], 0, 5));
    mem.reg[dest] = top | bottom;

}

void Rtype::JR(Memory& mem) {
    mem.branch(mem.reg[source1]);
}

void Rtype::JALR(Memory& mem) {
    mem.reg[dest] = mem.makeAddress(mem.ahead_pc) + 4;
    mem.branch(mem.reg[source1]);
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
    long int top = (-(long int)(mem.reg[source1] >> 31)) << 32;
    long int s1 = top | (long int)mem.reg[source1];
    top = (-(long int)(mem.reg[source2] >> 31)) << 32;
    long int s2 = top | (long int)mem.reg[source2];
    long int tmp = s1 * s2;
    std::cerr << tmp << '\n';
    mem.lo = tmp;
    mem.hi = tmp >> 32;

    std::cerr << mem.lo << ", " <<  mem.hi << '\n';
    mem.forward();
}

void Rtype::MULTU(Memory& mem){
    uint64_t s1 = mem.reg[source1];
    uint64_t s2 = mem.reg[source2];
    uint64_t tmp = s1 * s2;
    mem.lo = tmp;
    mem.hi = tmp >> 32;
    std::cerr << tmp << '\n';
    mem.forward();
}


void Rtype::ADD(Memory& mem) {
    int s1 = (int) mem.reg[source1];
    int s2 = (int) mem.reg[source2];
    if ( ( ((s1 + s2) <= 0) && ((s1 > 0) && (s2 > 0)) ) || ( ((s1 + s2) >= 0) && ((s1 < 0) && (s2 < 0)) ) ){
        std::cerr << "Overflow" << '\n';
        exit(-10);
    }
    mem.reg[dest] = (uint32_t)(s1 + s2);
    mem.forward();
}

void Rtype::ADDU(Memory& mem) {
    mem.reg[dest] = mem.reg[source1] + mem.reg[source2];
    mem.forward();
}

void Rtype::SUB(Memory& mem) {
    int s1 = (int) mem.reg[source1];
    int s2 = (int) mem.reg[source2];
    if ( ( ((s1 - s2) <= 0) && ((s1 > 0) && (s2 < 0)) ) || ( ((s1 - s2) >= 0) && ((s1 < 0) && (s2 > 0)) ) ){
        std::cerr << "Overflow" << '\n';
        exit(-10);
    }
    mem.reg[dest] = (uint32_t)(s1 - s2);
    mem.forward();
}

void Rtype::SUBU(Memory& mem) {
    mem.reg[dest] = mem.reg[source1] - mem.reg[source2];
    mem.forward();
}

void Rtype::AND(Memory& mem) {
    mem.reg[dest] = mem.reg[source1] & mem.reg[source2];
    mem.forward();
}

void Rtype::OR(Memory& mem) {
    mem.reg[dest] = mem.reg[source1] | mem.reg[source2];
    mem.forward();
}

void Rtype::XOR(Memory& mem) {
    mem.reg[dest] = mem.reg[source1] ^ mem.reg[source2];
    mem.forward();
}

void Rtype::DIV(Memory& mem) {
    if (mem.reg[source2] == 0){
        std::cerr << "Division by 0 error" << '\n';
        exit(-10);
    }
    int q = (int)mem.reg[source1] / (int)mem.reg[source2];
    int r = (int)mem.reg[source1] % (int)mem.reg[source2];
    std::cerr << q << ", " << r << '\n';
    mem.lo = (uint32_t)q;
    mem.hi = (uint32_t)r;
    mem.forward();
}

void Rtype::DIVU(Memory& mem) {
    if (mem.reg[source2] == 0){
        std::cerr << "Division by 0 error" << '\n';
        exit(-10);
    }
    uint32_t q = mem.reg[source1] / mem.reg[source2];
    uint32_t r = mem.reg[source1] % mem.reg[source2];
    std::cerr << q << ", " << r << '\n';
    mem.lo = q;
    mem.hi = r;
    mem.forward();
}

void Rtype::SLT(Memory& mem) {
    mem.reg[dest] = ((int)mem.reg[source1] < (int)mem.reg[source2]);
    mem.forward();
}

void Rtype::SLTU(Memory& mem) {
    mem.reg[dest] = (mem.reg[source1] < mem.reg[source2]);
    mem.forward();
}


//----------------------------------------------------------
//I-TYPE
void Itype::ADDI(Memory& mem){
    int s1 = (int) mem.reg[source1];
    int s2 = mem.sign_extend(immediate, 15);
    if ( ( ((s1 + s2) <= 0) && ((s1 > 0) && (s2 > 0)) ) || ( ((s1 + s2) >= 0) && ((s1 < 0) && (s2 < 0)) ) ){
        std::cerr << "Overflow" << '\n';
        exit(-10);
    }
    mem.reg[source2] = (uint32_t)(s1 + s2);
    mem.forward();
}

void Itype::ANDI(Memory& mem) {
    mem.reg[source2] = mem.reg[source1] & immediate;
    mem.forward();
}

void Itype::XORI(Memory& mem) {
    mem.reg[source2] = mem.reg[source1] ^ immediate;
    mem.forward();
}

void Itype::SLTI(Memory& mem) {
    mem.reg[source2] = ((int)mem.reg[source1] < (int)mem.sign_extend(immediate,15));
    mem.forward();
}

void Itype::SLTIU(Memory& mem) {
    mem.reg[source2] = (mem.reg[source1] < mem.sign_extend(immediate,15));
    mem.forward();
}

void Itype::ADDIU(Memory& mem){
    uint32_t s1 = mem.reg[source1];
    uint32_t s2 = mem.sign_extend(immediate, 15);
    mem.reg[source2] = (uint32_t)(s1 + s2);
    mem.forward();
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

void Itype::LB(Memory& mem){
    unsigned int effective = mem.reg[source1] + (int)mem.sign_extend(immediate, 15);
    std::string type ="";
    unsigned int value = mem.readConvert(type, effective);
    if (type == "imem"){
        mem.reg[source2] = mem.sign_extend(mem.imem[value], 7);
    } else if (type == "dmem"){
        mem.reg[source2] = mem.sign_extend(mem.dmem[value], 7);
    } else if (type == "getc"){
        mem.reg[source2] = mem.sign_extend(value, 7);
    }
    mem.forward();
}

void Itype::LBU(Memory& mem){
    unsigned int effective = mem.reg[source1] + (int)mem.sign_extend(immediate, 15);
    std::string type ="";
    unsigned int value = mem.readConvert(type, effective);
    if (type == "imem"){
        mem.reg[source2] = mem.imem[value];
    } else if (type == "dmem"){
        mem.reg[source2] = mem.dmem[value];
    } else if (type == "getc"){
        mem.reg[source2] = value;
    }
    mem.forward();
}

void Itype::SB(Memory& mem){
    unsigned int effective = mem.reg[source1] + (int)mem.sign_extend(immediate, 15);
    std::string type ="";
    unsigned int value = mem.writeConvert(type, effective);
    if (type == "dmem"){
        mem.dmem[value] = bitwise::isolate(mem.reg[source2], 0, 8);
    } else if (type == "putc"){
        std::putchar(bitwise::isolate(mem.reg[source2], 0, 8));
    }
    mem.forward();
}

void Itype::SH(Memory& mem){
    unsigned int effective = mem.reg[source1] + (int)mem.sign_extend(immediate, 15);
    if( effective % 2 != 0) {
        std::cerr << "Memory exception" << '\n';
        exit(-11);
    }
    std::string type ="";
    unsigned int value = mem.writeConvert(type, effective);
    if (type == "dmem"){
        mem.dmem[value+1] = bitwise::isolate(mem.reg[source2], 0, 8);
        mem.dmem[value] = bitwise::isolate(mem.reg[source2], 8, 8);
    } else if (type == "putc"){
        std::putchar(bitwise::isolate(mem.reg[source2], 0, 8));
    }
    mem.forward();
}

void Itype::LH(Memory& mem){
    unsigned int effective = (int)mem.sign_extend(immediate, 15) + mem.reg[source1];
    if( effective % 2 != 0) {
        std::cerr << "Memory exception" << '\n';
        exit(-11);
    }
    std::string type ="";
    unsigned int value = mem.readConvert(type, effective);
    if (type == "imem"){
        mem.reg[source2] = mem.sign_extend((mem.imem[value] << 8 | mem.imem[value + 1] ), 15);
    } else if (type == "dmem"){
        mem.reg[source2] = mem.sign_extend((mem.dmem[value] << 8 | mem.dmem[value + 1] ), 15);
    } else if (type == "getc"){
        mem.reg[source2] = mem.sign_extend(value, 8);
    }
    mem.forward();

}

void Itype::LHU(Memory& mem){
    unsigned int effective = (int)mem.sign_extend(immediate, 15) + mem.reg[source1];
    if( effective % 2 != 0) {
        std::cerr << "Memory exception" << '\n';
        exit(-11);
    }
    std::string type ="";
    unsigned int value = mem.readConvert(type, effective);
    if (type == "imem"){
        mem.reg[source2] = (mem.imem[value] << 8 | mem.imem[value + 1] );
    } else if (type == "dmem"){
        mem.reg[source2] = (mem.dmem[value] << 8 | mem.dmem[value + 1] );
    } else if (type == "getc"){
        mem.reg[source2] = value;
    }
    mem.forward();
}

void Itype::LW(Memory& mem){
    uint32_t location = mem.reg[source1] + (int)mem.sign_extend(immediate, 15);
    if (location % 4 != 0){
        std::cerr << "Address Error, not alligned address" << '\n';
        exit(-11);
    }
    std::string type = "";
    unsigned int value = mem.readConvert(type, location);
    if (type == "imem"){
        mem.reg[source2] = mem.instrToWord(value);
    } else if (type == "dmem"){
        mem.reg[source2] = mem.dataToWord(value);
    } else if (type == "getc"){
        mem.reg[source2] = mem.sign_extend(value, 7);
    }
    mem.forward();
}

void Itype::SW(Memory& mem){
    uint32_t location = mem.reg[source1] + (int)mem.sign_extend(immediate, 15);
    if (location % 4 != 0){
        std::cerr << "Address Error, not alligned address" << '\n';
        exit(-11);
    }
    std::string type = "";
    unsigned int value = mem.writeConvert(type, location);
    if (type == "dmem"){
        mem.dmem[value+3] = bitwise::isolate(mem.reg[source2], 0, 8);
        mem.dmem[value+2] = bitwise::isolate(mem.reg[source2], 8, 8);
        mem.dmem[value+1] = bitwise::isolate(mem.reg[source2], 16, 8);
        mem.dmem[value] = bitwise::isolate(mem.reg[source2], 24, 8);
    } else if (type == "putc"){
        std::cerr << bitwise::isolate(mem.reg[source2], 0, 8) << '\n';
        std::putchar(bitwise::isolate(mem.reg[source2], 0, 8));
    }
    mem.forward();
}


void Itype::LWL(Memory& mem){
    unsigned int location = mem.reg[source1] + (int)mem.sign_extend(immediate, 15);
    int shift = 0;
    int count = 3;
    do{
        std::string type = "";
        unsigned int value = mem.readConvert(type, location);
        if (type == "imem"){
            uint32_t shifted = mem.imem[value] << (24 - shift);
            mem.byteOverride(mem.reg[source2], count, shifted);
            std::cerr << bitwise::get_binary(mem.reg[source2]) << '\n';
        } else if (type == "dmem"){
            uint32_t shifted = mem.dmem[value] << (24 - shift);
            mem.byteOverride(mem.reg[source2], count, shifted);
            std::cerr << bitwise::get_binary(mem.reg[source2]) << '\n';
        }
        location++;
        shift += 8;
        count--;

    }while(location % 4 != 0);
    mem.forward();
}


void Itype::LWR(Memory& mem){
    unsigned int location = mem.reg[source1] + (int)mem.sign_extend(immediate, 15);
    int shift = 0;
    int count = 0;
    do{
        std::string type = "";
        unsigned int value = mem.readConvert(type, location);
        if (type == "imem"){
            int tmp = (int)mem.instrToWord(value);
            uint32_t shifted = mem.imem[value] << shift;
            mem.byteOverride(mem.reg[source2], count, shifted);
        } else if (type == "dmem"){
            uint32_t shifted = mem.dmem[value] << (shift);
            mem.byteOverride(mem.reg[source2], count, shifted);
            std::cerr << bitwise::get_binary(mem.reg[source2]) << '\n';
        }
        location--;
        shift += 8;
        count++;
    }while((location + 1) % 4 != 0);
    mem.forward();
}

void Itype::BGEZAL(Memory& mem) {
    mem.reg[31] = mem.makeAddress(mem.ahead_pc+4);

    if( ((int)mem.reg[source1]) >= 0) {
        int offset = mem.sign_extend( (immediate << 2), 17);
        mem.branch(mem.makeAddress(mem.ahead_pc) + offset);
    } else {
        mem.forward();
    }
}

void Itype::BLTZAL(Memory& mem) {
    mem.reg[31] = mem.makeAddress(mem.ahead_pc+4);

    if( ((int)mem.reg[source1]) < 0) {
        int offset = mem.sign_extend( (immediate << 2), 17);
        mem.branch(mem.makeAddress(mem.ahead_pc) + offset);
    } else {
        mem.forward();
    }
}

void Itype::BEQ(Memory& mem){
    if(mem.reg[source1] == mem.reg[source2]){
        int offset = mem.sign_extend( (immediate << 2 ), 17);
        mem.branch(mem.makeAddress(mem.ahead_pc) + offset);
    } else{
        mem.forward();
    }
}

void Itype::BGEZ(Memory& mem) {
    if( ((int)mem.reg[source1]) >= 0) {
        int offset = mem.sign_extend( (immediate << 2), 17);
        mem.branch(mem.makeAddress(mem.ahead_pc) + offset);
    } else {
        mem.forward();
    }
}

void Itype::BGTZ(Memory& mem) {
    if( ((int)mem.reg[source1]) > 0) {
        int offset = mem.sign_extend( (immediate << 2), 17);
        mem.branch(mem.makeAddress(mem.ahead_pc) + offset);
    } else {
        mem.forward();
    }
}

void Itype::BLEZ(Memory& mem) {
    if( ((int)mem.reg[source1]) <= 0) {
        int offset = mem.sign_extend( (immediate << 2), 17);
        mem.branch(mem.makeAddress(mem.ahead_pc) + offset);
    } else {
        mem.forward();
    }
}

void Itype::BLTZ(Memory& mem) {
    if( ((int)mem.reg[source1]) < 0) {
        int offset = mem.sign_extend( (immediate << 2), 17);
        mem.branch(mem.makeAddress(mem.ahead_pc) + offset);
    } else {
        mem.forward();
    }
}

void Itype::BNE(Memory& mem){
    if(mem.reg[source1] != mem.reg[source2]){
        int offset = mem.sign_extend( (immediate << 2 ), 17);
        mem.branch(mem.makeAddress(mem.ahead_pc) + offset);
    } else{
        mem.forward();
    }
}

//------------------------------------------------------------
//J-TYPE

void Jtype::JAL(Memory& mem) {
    mem.reg[31] = mem.makeAddress(mem.ahead_pc) + 4;
    uint32_t low_28b = address << 2;
    uint32_t high_4b = mem.makeAddress(mem.ahead_pc) & 0xF0000000;
    mem.branch(low_28b | high_4b);
}

void Jtype::J(Memory& mem) {
    uint32_t low_28b = address << 2;
    uint32_t high_4b = mem.makeAddress(mem.ahead_pc) & 0xF0000000;
    mem.branch(low_28b | high_4b);
}
