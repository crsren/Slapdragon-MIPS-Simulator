#ifndef MEMORY_H
#define MEMORY_H

#include <string>


class Memory{
public:
  const int imem_off = 0x10000000;
  const int imem_length = 0x1000000;

  const int dmem_off = 0x20000000;
  const int dmem_length = 0x4000000;

  int iconvert(uint32_t input);
  int dconvert(uint32_t input);



};




#endif
