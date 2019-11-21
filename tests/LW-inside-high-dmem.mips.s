# Created by nb2618
# edge case dmem high in LW
# Return code: 120

lui $7, 0x2400
ori $4, $4, 0x5678

sw $4, -4($7)
lw $2, -4($7)

jr $0
nop
