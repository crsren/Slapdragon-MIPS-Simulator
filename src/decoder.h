#ifndef DECODER_H
#define DECODER_H

#include <string>
#include <map> //change to unordered_map
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
    unsigned char source1;
    unsigned char source2;
    unsigned char dest;
    unsigned char shift_amt;
    unsigned char fnCode;

    void init(unsigned int& word);
    void run(Memory& mem);

    void SLL(Memory& mem);
    void ADDU(Memory& mem);
    void ADD(Memory& mem);
    void JR(Memory& mem);
    void MFHI(Memory& mem);

    //void JR();

    //LUT "fn code" <-> "pointer to function"
    //static std::map< unsigned char, void (*)(int) > fnMap;
    // std::map< unsigned char, void (*)(Memory& mem) > fnMap;
};

class Itype {
public:
    unsigned char opCode;
    unsigned char source1;
    unsigned char source2;
    unsigned int immediate;

    void init(unsigned int& word);
    void run(Memory& mem);

    void ADDI(Memory& mem);
    void LUI(Memory& mem);
    void ORI(Memory& mem);
    void LW(Memory& mem);

};

class Jtype {
public:
    unsigned int address;

    void init(unsigned int& word);
    void run(Memory& mem);
};

class instruction {
private:
    // int opCode : 6;
    unsigned char opCode;
public:
    char tag;
    Rtype r;
    Jtype j;
    Itype i;

    void init(unsigned int& word);
    void showContent();
    void run(Memory& mem);

    // void (*run) (Memory& mem);
};


#endif
