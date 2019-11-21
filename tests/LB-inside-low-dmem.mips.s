# Created by nb2618
# checks access to inside low dmem edge
# Return code: 86

lui $7, 0x2000

ori $4, $4, 0x5678

sw $4,   0($7)
lb $2,   0($7)

jr $0
nop
