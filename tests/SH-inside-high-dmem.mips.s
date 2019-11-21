# Created by nb2618
# storing data inside high dmem
# Return code: 234

ori $4, $4, 0xCDEA

lui $7, 0x2400


sh $4, -1($7)

lw $2, -4($7)



jr $0
nop
