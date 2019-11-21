# Created by car3418
# Adding to a negative integer without overflow
# Return code: 253

ori $8, $0, 0x0002
addi $9, $0, -5
#r8 = 2 and r9 = -5

add $2, $8, $9
#r2 = -3 = unsigned 253

jr $0

nop
