# Created by nb2618
# checks access to inside high imem edge
# Return code: 118

lui $7, 0x1100

ori $4, $4, 0x9876

sw $4,  -4($7)
lb $2,  -1($7)

jr $0
nop
