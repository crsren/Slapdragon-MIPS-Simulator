#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "decoder.h"
#include "helpers.h"
#include "cpu.h"

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

    std::vector<unsigned char> immembyte(std::istreambuf_iterator<char>(bin_stream), {});

    // std::cerr << "Read " << immembyte.size() << std::endl;
    Memory mem(immembyte);
    // printvector(mem.imem);


    instruction ins;
    while(1) {
        std::cerr << "PC at " << mem.pc << std::endl;

        uint32_t word = mem.instrToWord(mem.pc);
        std::cerr << bitwise::get_binary(word) << '\n';
        ins.init(word);
        ins.showContent();
        ins.run(mem);
        mem.showRegisters();

        if (mem.pc == -1){
            exit(bitwise::isolate(mem.reg[2], 0, 8));
        }
        // std::cin.get();
    }

    return 1;

}

// int main() {
//
//     uint32_t ching = 0b00010000000000000000000000000000;
//     std::cout << bitwise::get_binary(ching) << '\n';
//     std::cout << +ching << '\n';
//     std::cout << "Enter shift amount:" << '\n';
//     uint32_t shift_amt;
//     std::cin >> shift_amt;
//
//     uint32_t bottom = ching >> shift_amt;
//     uint32_t top = -(ching >> 31) << (32-shift_amt);
//     uint32_t chong = top | bottom;
//     std::cout << "Shifted by " << shift_amt << "bits: " << bitwise::get_binary(chong) << '\n';
//
//     return 0;
// }


void printvector(std::vector<uint8_t> v){
    std::cerr << "[";
    for (int i=0; i < v.size(); i++){
        std::cerr << bitwise::get_binary(v[i]) << ", ";
    }
    std::cerr << "]" << '\n';
}

void printvector(std::vector<uint32_t> v){
    for (int i=0; i < v.size(); i++){
        std::cerr << bitwise::get_binary(v[i]) << '\n';
    }
}
