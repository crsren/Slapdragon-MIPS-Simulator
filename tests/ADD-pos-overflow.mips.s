# Created by car3418
# Adding two positive integers wit overflow
# Return code: 246

lui $8, 0x7FFF
ori $8, $8, 0xFFFF
lui $9, 0x1
#r8 = max pos and r9 = max pos

add $2, $8, $9
#r2 = -10 (arithmetic overflow)

jr $0

nop
