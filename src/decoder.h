#ifndef DECODER_H
#define DECODER_H

#include <string>
//#include <map> //change to unordered_map
#include <functional>

#include "memory.h"


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
    void SRL(Memory& mem);
    void SRA(Memory& mem);
    void JR(Memory& mem);
    void MFHI(Memory& mem);
    void MTHI(Memory& mem);
    void MFLO(Memory& mem);
    void MTLO(Memory& mem);
    void MULT(Memory& mem);


    void ADD(Memory& mem);
    void ADDU(Memory& mem);

    void AND(Memory& mem);
    void DIV(Memory& mem);


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
    void ORI(Memory& mem);
    void LUI(Memory& mem);
    void LW(Memory& mem);
    void BEQ(Memory& mem);
    void LWL(Memory& mem);
    void LWR(Memory& mem);



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
