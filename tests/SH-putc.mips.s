# Created by nb2618
# checking storing to putc
# Return code: 0
# stdout: ?


ori $4, $4, 0xCD3F

lui $7, 0x3000
ori $7, $7, 0x0004


sh $4, 2($7)



jr $0
nop
