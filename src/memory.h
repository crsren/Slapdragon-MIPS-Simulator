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
  std::vector<uint32_t> imem;
  std::vector<uint32_t> dmem;

  uint32_t pc = 0;
  uint32_t ahead_pc = 1;
  uint32_t hi = 0;
  uint32_t lo = 0;

  Memory(std::vector<uint8_t>);
  Memory();

  void branch(uint8_t target);
  void forward();
  void showRegisters();

  //int iconvert(uint32_t input);
  //int dconvert(uint32_t input);

  unsigned int readconvert(std::string& type, uint32_t input);
  unsigned int writeconvert(std::string& type, uint32_t input);
  unsigned int execconvert(uint32_t input);
};




#endif
