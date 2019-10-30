#ifndef DECODER_H
#define DECODER_H

#include <string>

class Rtype {
private:
    // different parts

public:
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



public:
    enum{RTYPE, JTYPE, ITYPE} tag;
    union {
        Rtype r; //could be all named the same ("part")
        Jtype j;
        Itype i;
    };

    instruction(char in/* uint32_t word */);
    std::string content();
};


#endif
