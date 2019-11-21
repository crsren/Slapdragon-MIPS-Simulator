# Created by nb2618
# edge case writing inside low dmem
# Return code: 152

lui $4, 0x8000
ori $4, $4, 0x0098

lui $6, 0x2000

sb $4, 0($6)

lw $2, 0($6)

srl $2, $2, 24

jr $0
nop
