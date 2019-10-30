#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "decoder.h"


// cout for character printed by bitstream
// cerr for not genuine output

void printvector(std::vector<unsigned char> v);
std::vector<uint32_t> void convert(std::vector<unsigned char> vec);

int main(int argc, char *argv[]) {

    const int imem_off = 0x10000000;
    const int imem_length = 0x1000000;

    const int dmem_off = 0x20000000;
    const int dmem_length = 0x4000000;

    std::cerr << "Simulating binary " << argv[1] << std::endl;

    std::ifstream bin_stream(argv[1], std::ios::binary);


    //get length of binary instructions of input file
    bin_stream.seekg(0, bin_stream.end);
    int bin_length = bin_stream.tellg();
    bin_stream.seekg(0, bin_stream.beg);

    std::vector<uint32_t> imem;
    imem.resize(imem_length); //taking all memory


    // temporarily store all binary instructions character by character
    //char * buffer = new char[bin_length];
    //bin_stream.read(&buffer[0], bin_length);
    std::cout << bin_length << '\n';
    std::vector<unsigned char> immembyte(std::istreambuf_iterator<char>(bin_stream), {});

    std::cerr << "Read " << immembyte.size() << std::endl;
    printvector(immembyte);

    imem = conver(immembyte);

    std::cout << imem[0] << '\n';




    std::vector<uint32_t> dmem;
    dmem.resize(dmem_length);

    std::vector<uint32_t> reg = {0};
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
}



void printvector(std::vector<unsigned char> v){
  for (int i=0; i < v.size(); i++){
    std::cerr << +v[i] << '\n';
  }
}

std::vector<uint32_t> void convert(std::vector<unsigned char> vec){
  std::vector<uint32_t> final;
  for (int i=0; i < vec.size(); i++){
    uint32_t tmp = vec[0] | vec[1] << 8 | vec[2] << 16 | vec[3] << 32;
    std::cout << tmp << '\n';
    final.push_back(tmp);
  }
  return final;
}
/*int main() {

    cout << "Enter r j or i" << endl;
    char input;
    cin >> input;

    instruction yeye(input);

    cout << yeye.content() << endl;

    return 0;
}*/
