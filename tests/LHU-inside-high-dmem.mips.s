# Created by nb2618
# loading inside high dmem
# Return code: 52

lui $4, 0x1DC0
ori $4, $4, 0x1234

lui $6, 0x2400

sw $4,  -4($6)
lhu $2,  -2($6)

jr $0
nop
