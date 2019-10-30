#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "decoder.h"
#include "helpers.h"

// cout for character printed by bitstream
// cerr for not genuine output

/* int main(int argc, char *argv[]) {

    const int imem_off = 0x10000000;
    const int imem_length = 0x1000000;

    const int dmem_off = 0x20000000;
    const int dmem_length = 0x4000000;

    std::cerr << "Simulating binary " << argv[1] << endl;

    ifstream bin_stream(argv[1], ios::binary);

    //get length of binary instructions of input file
    bin_stream.seekg(0, bin_stream.end);
    int bin_length = bin_stream.tellg();
    bin_stream.seekg(0, bin_stream.beg);

    // temporarily store all binary instructions character by character
    char * buffer = new char[bin_length];
    bin_stream.read(&buffer[0], bin_length);

    cerr << "Read " << bin_length << " characters" << endl;

    vector<uint32_t> imem;
    imem.resize(imem_length);

    vector<uint32_t> dmem;
    dmem.resize(dmem_length);

    vector<uint32_t> reg;
    reg.resize(32);

    uint32_t pc = imem_off;

    while(1) {
        uint32_t instruction;
        if(pc == 0) {
            //execution finished
            exit(0);
        } else if(pc < imem_off) {

        } else if(pc < imem_off + imem_length) {
            instruction = imem[pc / 4]; // !!!!! why / 4
        } else {
            //memory exception
            exit(-11);
        }
    }

    return 1;
} */

int main(int argc, char *argv[]) {

    uint32_t ching = 0b11111111111111111111110000000000;
    instruction yeye(ching);
    //uint8_t chong = bitwise::isolate8(ching,0,6);

    //std::cout << unsigned(chong) << std::endl;

    yeye.showContent();

    return 0;
}
