#ifndef DECODER_H
#define DECODER_H

#include <string>
//#include <map> //change to unordered_map
#include <functional>

#include "cpu.h"


struct Rtype {
//public:
    //custom size or just 8bit (like rn) ??
    // int source1 : 5;
    // int source2 : 5;
    // int dest: 5;
    // int shift_amt: 5;
    // int fnCode: 6;
    uint8_t source1;
    uint8_t source2;
    uint8_t dest;
    uint8_t shift_amt;
    uint8_t fnCode;

    void init(uint32_t& word);
    void run(Memory& mem);

    void SLL(Memory& mem);
    void SLLV(Memory& mem);
    void SRL(Memory& mem);
    void SRLV(Memory& mem);
    void SRA(Memory& mem);
    void SRAV(Memory& mem);
    void JR(Memory& mem);
    void JALR(Memory& mem);
    void MFHI(Memory& mem);
    void MTHI(Memory& mem);
    void MFLO(Memory& mem);
    void MTLO(Memory& mem);
    void MULT(Memory& mem);
    void MULTU(Memory& mem);

    void ADD(Memory& mem);
    void ADDU(Memory& mem);
    void SUB(Memory& mem);
    void SUBU(Memory& mem);

    void AND(Memory& mem);
    void OR(Memory& mem);
    void XOR(Memory& mem);

    void DIV(Memory& mem);
    void DIVU(Memory& mem);

    void SLT(Memory& mem);
    void SLTU(Memory& mem);

    //LUT "fn code" <-> "pointer to function"
    //static std::map< uint8_t, void (*)(int) > fnMap;
    // std::map< uint8_t, void (*)(Memory& mem) > fnMap;
};

class Itype {
public:
    uint8_t opCode;
    uint8_t source1;
    uint8_t source2;
    uint32_t immediate;

    void init(uint32_t& word);
    void run(Memory& mem);

    void ADDI(Memory& mem);
    void ADDIU(Memory& mem);
    void ORI(Memory& mem);
    void LUI(Memory& mem);
    void LW(Memory& mem);
    void SW(Memory& mem);
    void BEQ(Memory& mem);
    void LB(Memory& mem);
    void LBU(Memory& mem);
    void LH(Memory& mem);
    void LHU(Memory& mem);
    void LWL(Memory& mem);
    void LWR(Memory& mem);
    void BGEZAL(Memory& mem);
    void BLTZAL(Memory& mem);
    void BGEZ(Memory& mem);
    void BGTZ(Memory& mem);
    void BLEZ(Memory& mem);
    void BLTZ(Memory& mem);
    void SLTI(Memory& mem);
    void SLTIU(Memory& mem);




};

class Jtype {
public:
    uint32_t address;

    void init(uint32_t& word);
    void run(Memory& mem);
};

class instruction {
private:
    // int opCode : 6;
    uint8_t opCode;
public:
    char tag;
    Rtype r;
    Jtype j;
    Itype i;

    void init(uint32_t& word);
    void showContent();
    void run(Memory& mem);

    // void (*run) (Memory& mem);
};


#endif
