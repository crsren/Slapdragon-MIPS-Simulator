# Created by nb2618
# checks access to inside low imem edge
# Return code: 137

lui $7, 0x1000

lui $4, 0x89A4

sw $4,  0($7)
lb $2,  0($7)

jr $0
nop
