#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

#include "decoder.h"
#include "helpers.h"

// cout for character printed by bitstream
// cerr for not genuine output

const int imem_off = 0x10000000;
const int imem_length = 0x1000000;

const int dmem_off = 0x20000000;
const int dmem_length = 0x4000000;

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

    std::vector<uint32_t> imem;
    imem.resize(bin_length); //taking all memory


    // temporarily store all binary instructions character by character
    //char * buffer = new char[bin_length];
    //bin_stream.read(&buffer[0], bin_length);
    std::cerr << bin_length << '\n';
    std::vector<unsigned char> immembyte(std::istreambuf_iterator<char>(bin_stream), {});

    std::cerr << "Read " << immembyte.size() << std::endl;
    //printvector(immembyte);
    imem = convert(immembyte);

    printvector(imem);

    std::vector<uint32_t> dmem;
    dmem.resize(dmem_length);

    std::vector<uint32_t> reg = {0};
    reg.resize(32);

    int pc = 0;

    while(1) {

      //next(pc);

      if (pc == imem.size()){
        std::cout << "Sucess finished" << '\n';
        exit(0);
      }

      uint32_t word = imem[pc]; // !!!!! why / 4
      instruction current(word);
      current.showContent();
      memhelp::showregisters(reg);

      //} else {
          //memory exception
        //  exit(-11);
      //}
      pc++;
    }

    return 1;
}


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

std::vector<uint32_t> convert(std::vector<unsigned char> vec){
  std::vector<uint32_t> final;
  for (int i=0; i < vec.size(); i = i + 4){
    uint32_t tmp = vec[i] | vec[i+1] << 8 | vec[i+2] << 16 | vec[i+3] << 24;
    final.push_back(tmp);
  }
  return final;
}
