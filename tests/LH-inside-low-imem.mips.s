# Created by nb2618
# loading inside low imem
# Return code: 1

lui $4, 0x8001
ori $4, $4, 0xD469

lui $6, 0x1000

sw $4, 0($6)
lh $2, 0($6)

jr $0
nop
