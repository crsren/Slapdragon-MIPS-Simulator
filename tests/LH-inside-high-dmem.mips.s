# Created by nb2618
# loading inside high dmem
# Return code: 153

lui $4, $1DC0
ori $4, $4, 0xDE99

lui $6, 0x2400

sw $4,  -4($6)
lh $2,  -2($6)

jr $0
nop
