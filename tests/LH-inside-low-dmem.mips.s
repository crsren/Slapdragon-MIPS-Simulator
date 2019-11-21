# Created by nb2618
# loading inside low dmem
# Return code: 61

lui $4, 1222
ori $4, $4, 0x373D

lui $6, 0x2000

sw $4,   4($6)
lh $2,   2($6)

jr $0
nop
