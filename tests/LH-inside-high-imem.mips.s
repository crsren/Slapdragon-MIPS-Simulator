# Created by nb2618
# loading inside high imem
# Return code: 221

lui $4, 0x8001
ori $4, $4, 0xD4DD

lui $6, 0x1100

sw $4, -4($6)
lh $2, -2($6)

jr $0
nop
