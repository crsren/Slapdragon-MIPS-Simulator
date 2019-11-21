# Created by nb2618
# testing normal operation for LBU
# Return code: 52

lui $7, 0x1000
ori $4, $4, 0x1234

sw $4,  0($7)
lbu $2,  3($7)

jr $0
nop
