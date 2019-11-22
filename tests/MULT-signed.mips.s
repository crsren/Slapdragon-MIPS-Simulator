#created by: car3418
#Testing signed functionality of MULT
# return code: 177
# stdout: [

lui     $4, 0xff4f
ori     $4, $4, 0x33ff
#-11586561
lui     $6, $6, 0x0000
ori     $6, $6, 0x3FFF
# 81.919
mult    $4, $6

nop
nop
mflo    $10     #0xCDB08C01
mfhi    $11     #0xFFFFFFD3

add     $2, $2, $10
# 0xffd037b1, b1 is 117
lui     $7, 0x3000
ori     $1, $1, 113
sub     $11, $11, $1
# gives 0x48808c5b, 5b is [
sw      $11, 4($7)

jr      $0
nop
nop
