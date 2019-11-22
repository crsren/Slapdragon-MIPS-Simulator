# Created by nb2618
# normal operation test high bits overwrite
# Return code: 33
# stdout: L

lui $7, 0x2000

lui $2, 0x2100

lui $4, 0x5B4C
ori $4, $4, 0x44BB

lui $10, 0x3000

sw $4,  0($7)
lwr $2,  2($7)
srl $4, $2, 8
srl $2, $2, 24
sb $4, 7($10)

jr $0
nop
