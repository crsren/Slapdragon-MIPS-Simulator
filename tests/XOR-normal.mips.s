#created by: nb2618
#Testing the basic functionality of XOR
#return code: 170

lui     $4, 0x114f
ori     $4, $4, 0x33E5
lui     $5, 0x114f
ori     $5, $5, 0x334f
xor     $2, $5, $4

jr      $0
nop
