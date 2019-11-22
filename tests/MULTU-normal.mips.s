#created by: car3418
#Testing unsigned functionality of MULTU
#return code: 251
# stdout: W

lui     $4, 0xff4f
ori     $4, $4, 0x33ff
ori     $6, $6, 5

mult    $4, $6
# result 0xFC8C03FB is 4237034491

mflo    $2     #0xfc8c03fb
mfhi    $11     # is -1

lui     $7, 0x3000
andi    $11, $11, 87
# gives 01010111 which is W
sw      $11, 4($7)

jr      $0
nop
nop
