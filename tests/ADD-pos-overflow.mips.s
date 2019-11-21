# Created by car3418
# Adding two positive integers wit overflow
# Return code: 246

lui $8, 0x7FFF
lui $9, 0x7FFF
#r8 = max pos and r9 = max pos

add $2, $8, $9
#r2 = -10 (arithmetic overflow)

jr $0

nop
