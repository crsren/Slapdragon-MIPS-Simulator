# Created by nb2618
# normal operation test joined LWL and LWR
# Return code: 187
# stdout: T

lui $7, 0x2000

lui $2, 0x2100

lui $4, 0x545B
ori $4, $4, 0x44BB

lui $10, 0x3000

sw $4,  0($7)
lwl $2,  2($7)
nop
lwr $2, 1($7)
srl $2, $2, 8
sb $2, 7($10)
srl $2, $2, 8


jr $0
nop
