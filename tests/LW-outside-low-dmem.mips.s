# Created by nb2618
# edge case dmem low out LW
# Return code: 245

lui $7, 0x2000
ori $4, $4, 0x4321

lw $2, -4($7)

jr $0
nop
