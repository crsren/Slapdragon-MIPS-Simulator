# Created by nb2618
# storing data inside high dmem
# Return code: 245

ori $4, $4, 0xCDEA

lui $7, 0x2400


sh $4, 0($7)


jr $0
nop
