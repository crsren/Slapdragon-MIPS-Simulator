# Created by nb2618
# edge case imem low in LW
# Return code: 60

lui $7, 0x1000
lui $4, 0xCDBA

lw $2, 0($7)
srl $2, $2, 24

jr $0
nop
