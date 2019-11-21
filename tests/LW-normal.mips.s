# Created by nb2618
# test for normal operation of LW
# Return code: 103

lui $4, 0x8000
ori $4, $4, 0x4567

lui $7, 0x2000

sw $4, 0($6)

lw $2, 0($6)

jr $0
nop
