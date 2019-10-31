#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "decoder.h"
#include "helpers.h"

// cout for character printed by bitstream
// cerr for not genuine output

int main(int argc, char *argv[]) {

    uint32_t ching = 0b0000100001000010000100001000000;
    instruction yeye(ching);
    // uint8_t chong = bitwise::isolate8(ching,10,6);

    // std::bitset<8> x(chong);
    // std::cout << x << std::endl;
    yeye.showContent();
    // std::cout << bitwise::get_binary(yeye.r.source1) << std::endl;

    return 0;
}
