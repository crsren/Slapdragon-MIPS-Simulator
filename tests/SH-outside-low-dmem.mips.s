# Created by nb2618
# storing data outside low dmem
# Return code: 245

ori $4, $4, 0x0110

lui $7, 0x2000

sh $4, -2($7)


jr $0
nop
