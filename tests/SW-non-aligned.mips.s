# Created by nb2618
# Loading a non aligned word with SW, expecting a memory error.
# Return code: 251

lui $4, 0x8000
ori $4, $4, 0x4567

lui $6, 0x2000

sw $4, 2($6)

lb $2, 3($6)

jr $0
nop
