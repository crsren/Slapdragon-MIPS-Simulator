# Created by car3418
# Adding two negative numbers ignoring the overflow
# Return code: 2

addi $9, $0, 0xF001
addu $2, $9, $9
#r2 = 2 because overflow ignored

jr $0
nop
