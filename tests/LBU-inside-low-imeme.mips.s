# Created by nb2618
# checks access to inside low imem edge
# Return code: 69

lui $7, 0x1000

lui $4, 0x4564

sw $4,  0($7)
lbu $2,  0($7)

jr $0
nop
