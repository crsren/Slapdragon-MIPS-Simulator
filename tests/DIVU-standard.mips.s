# Created by car3418
# Checks if normal unsigned devision works
# Return code: 207
# Stdout: X

lui $8, 0x00BC
addi $8, 0x614E
#r8 = 12345678
lui $9, 0x0013
#r9 = 19

divu $8, $9
# is 649772,52632

#hi should be 0x0009EA2C
lui $4, 0x3000
ori $4, 4
#use r4 to store addr_putc
mfhi $3
# LSb is 0x2c = 0b00101100
# shift by one to the left to get ASCII X
sll $3, $3, 1
sb $3, 0($4)


#lo should be 0x00086bcf
mflo $2
$2 lowest 8 bits of lo = 0xcf = 207


jr $0
nop
