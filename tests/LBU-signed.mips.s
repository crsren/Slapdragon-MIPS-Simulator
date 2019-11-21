# Created by nb2618
# testing zero extension LBU
# Return code: 0

lui $7, 0x1000
ori $4, $4, 0x12FF

sw $4,  0($7)
lbu $2,  3($7)
srl $2, $2, 12

jr $0
nop
