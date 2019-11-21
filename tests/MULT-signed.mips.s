#created by: nb2618
#Testing signed functionality of MULT
#return code: 0
#cout: 0 177

lui     $4, 0xff4f
ori     $4, $4, 0x33ff #-11586561
lui     $6, 0x4530
ori     $6, $6, 0x3FFF # 1160790015
mult    $4, $6  #result 0xFFD037B15B656800
nop
nop
mflo    $10     #0x5B656800
mfhi    $11     #0xFFD037B1

lui     $7, 0x3000
sw      $10, 4($7)
sw      $11, 4($7)

jr      $0
nop
nop
