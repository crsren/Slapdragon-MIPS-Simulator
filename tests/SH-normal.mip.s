# Created by nb2618
# test for normal operation of SH
# Return code: 120

lui $4, 0x1234
ori $4, $4, 0x5678

lui $7, 0x2000

sh $4, 2($7)

lw $2, 0($7)

jr $0
nop
