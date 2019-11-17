#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <vector>


class Memory{
public:
  const int null_off = 0;

  const int imem_off = 0x10000000;
  const int imem_length = 0x1000000;

  const int dmem_off = 0x20000000;
  const int dmem_length = 0x4000000;

  const int getc_off = 0x30000000;

  const int putc_off = 0x30000004;


  int bin_length;

  std::vector<uint32_t> reg;
  std::vector<uint8_t> imem;
  std::vector<uint8_t> dmem;

  uint32_t pc = 0;
  uint32_t ahead_pc = 4;
  uint32_t hi = 0;
  uint32_t lo = 0;

  Memory(std::vector<uint8_t>);
  Memory();

  void branch(uint8_t target);
  void forward();
  void showRegisters();
  uint32_t instrToWord(int start);
  uint32_t dataToWord(int start);


  unsigned int readConvert(std::string& type, uint32_t input);
  unsigned int writeConvert(std::string& type, uint32_t input);
  unsigned int execConvert(uint32_t input);
};




#endif
