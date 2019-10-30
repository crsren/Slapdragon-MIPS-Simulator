#ifndef DECODER_H
#define DECODER_H

#include <string>

class Rtype {
private:
    // different parts

public:
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
    // constructor to cut in parts
    // int i = 1;
};

class Itype {
private:
    // different parts

public:
    // constructor to cut in parts
    // int i = 2;
};

class Jtype {
private:
    // different parts

public:
    // constructor to cut in parts
    // int i = 3;
};

class instruction {
private:
    int opCode : 6;
public:
    enum{RTYPE, JTYPE, ITYPE} tag;
    union {
        Rtype r; //could be all named the same ("part")
        Jtype j;
        Itype i;
    };

    instruction(uint32_t& word);
    std::string content();
};


#endif
