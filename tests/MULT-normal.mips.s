#created by: nb2618
#Testing normal functionality of MULT
#return code: 0
#cout: 1 255

lui     $4, 0x4fff
ori     $4, $4, 0xffff
lui     $6, 0x7F30
ori     $6, $6, 0x3FFF
mult    $4, $6  #result 0x27BF13FF30CFC001
nop
nop
mflo    $10     #0x30CFC001
mfhi    $11     #0x27BF13FF

lui     $7, 0x3000
sw      $10, 4($7)
sw      $11, 4($7)

jr      $0
nop
