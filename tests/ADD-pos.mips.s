# Created by car3418
# Adding two positive integers without overflow
# Return code: 40

ori $8, $0, 0x0012
addi $9, $0, 22
#r8 = 18 and r9 = 22

add $2, $8, $9
#r2 = 40

jr $0
nop
