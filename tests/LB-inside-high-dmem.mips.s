# Created by nb2618
# checks access to inside high dmem edge
# Return code: 144

lui $7, 0x2400

ori $4, $4, 0x7890

sw $4,  -4($7)
lb $2,  -1($7)

jr $0
nop
