#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "decoder.h"
#include "helpers.h"
#include "memory.h"

// cout for character printed by bitstream
// cerr for not genuine output

void printvector(std::vector<unsigned char> v);
std::vector<uint32_t> convert(std::vector<unsigned char> vec);
void printvector(std::vector<uint32_t> v);

int main(int argc, char *argv[]) {



    std::cerr << "Simulating binary " << argv[1] << std::endl;

    std::ifstream bin_stream(argv[1], std::ios::binary);


    //get length of binary instructions of input file
    bin_stream.seekg(0, bin_stream.end);
    int bin_length = bin_stream.tellg();
    bin_stream.seekg(0, bin_stream.beg);

    std::cerr << bin_length << '\n';
    std::vector<unsigned char> immembyte(std::istreambuf_iterator<char>(bin_stream), {});

    std::cerr << "Read " << immembyte.size() << std::endl;
    printvector(immembyte);
    Memory mem(immembyte);


    instruction ins;
    while(1) {


        if (mem.pc >= mem.imem.size()){
            std::cerr << "Sucess finished" << '\n';
            exit(0);
        } else {
            std::cerr << "PC at " << mem.pc << std::endl;
        }

        uint32_t word = mem.imem[mem.pc]; // !!!!! why / 4
        ins.init(word);
        ins.showContent();
        ins.run(mem);
        //mem.showRegisters();

    }

    return 1;

}

// int main() {
// std::vector<uint32_t> reg = {0};
// reg.resize(32);
// reg[1] = 1;
// reg[2] = 2;
// memhelp::showregisters(reg);
//
// uint32_t pc = 0;
// uint32_t input = 0b10000100000001000001000001000000;
// instruction ins;
// ins.init(input);
// ins.showContent();
// ins.run(pc, reg);
// memhelp::showregisters(reg);
//
//     return 0;
// }


void printvector(std::vector<unsigned char> v){
    for (int i=0; i < v.size(); i++){
        std::cerr << bitwise::get_binary(v[i]) << '\n';
    }
}

void printvector(std::vector<uint32_t> v){
    for (int i=0; i < v.size(); i++){
        std::cerr << bitwise::get_binary(v[i]) << '\n';

    }
}
