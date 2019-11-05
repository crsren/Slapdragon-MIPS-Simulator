#ifndef DECODER_H
#define DECODER_H

#include <string>
#include <map>
#include <functional>


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
    void ADDU(std::vector<uint32_t> &registers);
    void JR(uint32_t& pc, const std::vector<uint32_t> &registers);
    void test();
    //void JR();
    //void show(); only if could have same name

    //LUT "pointer to function " <-> "fn code"
    static std::map<uint8_t, std::function<void()>> fnMap = {
							{ 0x21, [this] { Rtype.test(); } }
            };
};

class Itype {
public:
    uint8_t source1;
    uint8_t source2;
    uint32_t address;

    void init(uint32_t& word);
    void ADDI(std::vector<uint32_t> &registers);
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
    void run();
};


#endif
