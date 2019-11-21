# Created by nb2618
# checking if only half a word is written
# Return code: 0

ori $4, $4, 0xCDEA

lui $7, 0x2000


sh $4, 0($7)

lw $2, 0($7)


jr $0
nop
