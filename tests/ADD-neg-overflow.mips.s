# Created by car3418
# Adding two negative integers wit overflow
# Return code: 246

lui $8, 0x8000
addi $9, $0, -1

# solution is 0x7FFF
add $2, $8, $9
#r2 = -10 (arithmetic overflow)

jr $0

nop
