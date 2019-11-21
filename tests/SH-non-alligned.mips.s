# Created by nb2618
# storing to a non aligned address
# Return code: 245

lui $4, 0x1234
ori $4, $4, 0x5678

lui $7, 0x2000

sh $4, 1($7)

lw $2, 0($7)

jr $0
nop
