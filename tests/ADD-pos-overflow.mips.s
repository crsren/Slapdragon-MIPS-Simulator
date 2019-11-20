# Created by car3418
# Adding two negative integers wit overflow
# Return code: -10

lui $8, 0x8000
addi $9, $0, -1
#r8 = -2147483648 and r9 = -1

add $2, $8, $9
#r2 = -10 (arithmetic overflow)

jr $0

