#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "decoder.h"
#include "helpers.h"
#include "cpu.h"

void printvector(std::vector<unsigned char> v);
std::vector<uint32_t> convert(std::vector<unsigned char> vec);
void printvector(std::vector<uint32_t> v);


int main(int argc,  char *argv[]) {




    std::cerr << "Simulating binary " << argv[1] << std::endl;

    std::ifstream bin_stream(argv[1], std::ios::binary);


    //get length of binary instructions of input file
    bin_stream.seekg(0, bin_stream.end);
    bin_stream.seekg(0, bin_stream.beg);

    std::vector<unsigned char> immembyte(std::istreambuf_iterator<char>(bin_stream), {});

    Memory mem(immembyte);
    // printvector(mem.imem);
    int counter = 0;

    instruction ins;
    while(1) {
        std::cerr << "PC at " << mem.pc << std::endl;
        std::cerr << "Ahead_PC at " << mem.ahead_pc << std::endl;

        uint32_t word = mem.instrToWord(mem.pc);
        ins.init(word);
        std::cerr << bitwise::get_binary(word) << '\n';
        ins.showContent();
        ins.run(mem);
        mem.showRegisters();
        if ((int)mem.pc == -1){
            exit(bitwise::isolate(mem.reg[2], 0, 8));
        }

        if (counter == 200){
          exit(-1);
        }
        counter++;

    }

    return 1;

}

void printvector(std::vector<uint8_t> v){
    std::cerr << "[";
    for (unsigned int i=0; i < v.size(); i++){
        std::cerr << bitwise::get_binary(v[i]) << ", ";
    }
    std::cerr << "]" << '\n';
}

void printvector(std::vector<uint32_t> v){
    for (unsigned int i=0; i < v.size(); i++){
        std::cerr << bitwise::get_binary(v[i]) << '\n';
    }
}
