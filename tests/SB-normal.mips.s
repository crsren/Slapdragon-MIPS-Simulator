# Created by nb2618
# Testing normal function of SB
# Return code: 115

lui $4, 0x8000
ori $4, $4, 0xD473

lui $6, 0x2000

sb $4, 1($6)

lw $2, 0($6)

srl $2, $2, 16

jr $0
nop
