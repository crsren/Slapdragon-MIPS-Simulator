#ifndef DECODER_H
#define DECODER_H

#include <string>

class Rtype {
public:
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
    //void show(); only if could have same name
};

class Itype {
public:
    uint8_t source1;
    uint8_t source2;
    uint32_t address;

    void init(uint32_t& word);
};

class Jtype {
public:
    uint32_t address;

    void init(uint32_t& word);
};

class instruction {
private:
    // int opCode : 6;
    uint8_t opCode;
public:
    enum{RTYPE, JTYPE, ITYPE} tag;
    union {
        // CAN THIS SOMEHOW WORK? WOULD ALLOW CALLING "<instruction>.content.show()"
        // Rtype content;
        // Jtype content;
        // Itype content;
        Rtype r;
        Jtype j;
        Itype i;
    };

    instruction(uint32_t& word);
    void showContent();
};


#endif
