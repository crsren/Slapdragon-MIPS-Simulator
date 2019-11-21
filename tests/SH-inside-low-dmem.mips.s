# Created by nb2618
# storing
# Return code: 16

ori $4, $4, 0x0110

lui $7, 0x2000

sh $4, 0($7)

lw $2, 0($7)

srl $2, $2, 16

jr $0
nop
