# Created by nb2618
# normal operation test
# Return code: 187
# stdout: d

lui $7, 0x2000

lui $4, 0xDEBB
ori $4, $4, 0x1234

ori $2, $2, 100

lui $10, 0x3000

sw $4,  0($7)
lwl $2,  1($7)
sb   $2, 7($10)
srl $2, $2, 24

jr $0
nop
