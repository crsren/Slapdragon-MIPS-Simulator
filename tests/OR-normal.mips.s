#created by: nb2618
#Testing the basic functionality of OR
#return code: 231

lui     $4, 0x114f
ori     $4, $4, 0x33E5
lui     $6, 0x4220
ori     $6, $6, 0x3C83
or      $2 $4, $6

jr      $0
nop
nop
