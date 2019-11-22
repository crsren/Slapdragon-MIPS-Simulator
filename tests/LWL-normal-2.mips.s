# Created by nb2618
# normal operation test
# Return code: 52
# stdout: 0

lui $7, 0x2000

lui $4, 0xDEBB
ori $4, $4, 0x1234

lui $10, 0x3000

sw $4,  0($7)
lwl $2,  3($7)
srl $2, $2, 16
lb   $2, 7($10)
srl $2, $2, 8

jr $0
nop
