#ifndef CPU_H
#define CPU_H

#include <string>
#include <vector>


class Memory{
public:
  const unsigned int null_off = 0;

  const unsigned int imem_off = 0x10000000;
  const unsigned int imem_length = 0x1000000;

  const unsigned int dmem_off = 0x20000000;
  const unsigned int dmem_length = 0x4000000;

  const unsigned int getc_off = 0x30000000;

  const unsigned int putc_off = 0x30000004;


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

  void branch(uint32_t target);
  void forward();
  void showRegisters();
  void checkDmem();
  uint32_t instrToWord(int start);
  uint32_t dataToWord(int start);
  uint32_t sign_extend(uint32_t word, int msb);
  void byteOverride(uint32_t& word, int start, uint32_t newbyte);



  unsigned int readConvert(std::string& type, uint32_t input);
  unsigned int writeConvert(std::string& type, uint32_t input);
  unsigned int execConvert(uint32_t input);

  uint32_t makeAddress(int pc);
};


#endif
