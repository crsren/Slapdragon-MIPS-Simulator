# Created by nb2618
# testing normal operation for LBU
# Return code: 16

lui $7, 0x1000
ori $4, $4, 0x1234

lbu $2,  2($7)

jr $0
nop
