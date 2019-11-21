# Created by nb2618
# edge case imem low in LW
# Return code: 186

lui $7, 0x1000
ori $4, $4, 0xCDBA

sw $4, 0($7)
lw $2, 0($7)

jr $0
nop
