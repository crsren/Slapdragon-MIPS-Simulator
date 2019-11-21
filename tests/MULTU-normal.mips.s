#created by: nb2618
#Testing signed functionality of MULT
#return code: 0
#cout: 0 19

lui     $4, 0xff4f
ori     $4, $4, 0x33ff # 4283380735
lui     $6, 0x4530
ori     $6, $6, 0x3FFF # 18572640255
mult    $4, $6  #result 0x50077B137DACC000
nop
nop
mflo    $10     #0x7DACC000
mfhi    $11     #0x50077B13

lui     $7, 0x3000
sw      $10, 4($7)
sw      $11, 4($7)

jr      $0
nop
nop
