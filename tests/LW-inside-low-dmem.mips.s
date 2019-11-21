# Created by nb2618
# edge case dmem low in LW
# Return code: 33

lui $7, 0x2000
ori $4, $4, 0x4321

sw $4, 0($7)
lw $2, 0($7)

jr $0
nop
