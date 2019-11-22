# Created by nb2618
# edge case imem high in LW
# Return code: 0

lui $7, 0x1100
ori $4, $4, 0x1234

lw $2, -4($7)

jr $0
nop
