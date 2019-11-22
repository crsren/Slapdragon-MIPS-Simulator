# Created by nb2618
# aligned test
# Return code: 222

lui $7, 0x2000

lui $4, 0x34BB
ori $4, $4, 0x12DE

lui $10, 0x3000

sw $4,  0($7)
lwr $2,  3($7)

jr $0
nop
