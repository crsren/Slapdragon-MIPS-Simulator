# Created by nb2618
# checks access to inside high dmem edge
# Return code: 132

lui $7, 0x2400

ori $4, $4, 0xDE84

sw $4,  -4($7)
lbu $2,  -1($7)

jr $0
nop
