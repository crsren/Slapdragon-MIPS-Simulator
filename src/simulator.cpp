#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "decoder.h"
#include "helpers.h"
#include "cpu.h"

int main(int argc,  char *argv[]) {

    std::cerr << "Simulating binary " << argv[1] << std::endl;

    std::ifstream bin_stream(argv[1], std::ios::binary);


    //get length of binary instructions of input file
    bin_stream.seekg(0, bin_stream.end);
    bin_stream.seekg(0, bin_stream.beg);

    std::vector<unsigned char> immembyte(std::istreambuf_iterator<char>(bin_stream), {});

    Memory mem(immembyte);
    int counter = 0;

    instruction ins;
    while(1) {
        //std::cerr << "PC at " << mem.pc << std::endl;
        //std::cerr << "Ahead_PC at " << mem.ahead_pc << std::endl;

        uint32_t word = mem.instrToWord(mem.pc);
        ins.init(word);
        //ins.showContent();
        ins.run(mem);
        //mem.showRegisters();
        if ((int)mem.pc == -1){
            exit(bitwise::isolate(mem.reg[2], 0, 8));
        }

        if (counter == 20000){
          exit(-1);
        }
        counter++;

    }

    return 1;

}
