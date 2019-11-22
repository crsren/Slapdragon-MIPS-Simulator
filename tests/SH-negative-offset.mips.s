# Created by nb2618
# testing negative offset
# Return code: 146

ori $4, $4, 0x8392

lui $7, 0x2000
ori $7, $7, 0x0004

lui $8, 0x2000


sh $4, -4($7)

lw $2, 0($8)

srl $2, $2, 16

jr $0
nop
