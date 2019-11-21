# Created by nb2618
# edge case imem high out LW
# Return code: 245

lui $7, 0x1100
ori $4, $4, 0x1234

lw $2, 0($7)

jr $0
nop
