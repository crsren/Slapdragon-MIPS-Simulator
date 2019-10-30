#ifndef DECODER_H
#define DECODER_H

#include <string>

class instruction {
private:

    enum{RTYPE, JTYPE, ITYPE} type
    union {
        Rtype r; //could be all named the same ("part")
        Jtype k;
        Itype i;
    }

public:
    void instruction(/* uint32_t word */);
    std::string content();
}

class Rtype {
private:
    // different parts

public:
    // constructor to cut in parts

}

class Itype {
private:
    // different parts

public:
    // constructor to cut in parts

}

class Jtype {
private:
    // different parts

public:
    // constructor to cut in parts

}


#endif
