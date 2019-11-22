# Created by nb2618
# checks access to inside low dmem edge
# Return code: 152

lui $7, 0x2000

ori $4, $4, 0x9876

sw $4,   0($7)
lbu $2,   2($7)

jr $0
nop
