#created by: nb2618
#Testing the basic functionality of ORI
#return code: 239

lui     $4, 0x114f
ori     $4, $4, 0x33E5
ori      $2, $4, 0x008E

jr      $0
nop
nop
