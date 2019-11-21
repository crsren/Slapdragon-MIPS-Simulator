# Created by nb2618
# edge case imem low out LW
# Return code: 245

lui $7, 0x1000

lw $2, -4($7)

jr $0
nop
