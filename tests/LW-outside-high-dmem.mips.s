# Created by nb2618
# edge case dmem high out LW
# Return code: 245

lui $7, 0x2400
ori $4, $4, 0x5678

sw $4, 0($7)
lw $2, 0($7)

jr $0
nop
