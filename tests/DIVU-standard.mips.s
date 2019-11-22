# Created by car3418
# Checks if normal unsigned devision works
# Return code: 13
# Stdout: 6


lui $8, 0x80BC
addi $8, $8, 0x614E
ori $9, $9, 0x0013
#r9 is 19

divu $8, $9
# quotient 0x6C68BDB
# remainder 13

mfhi $2

mflo $10
andi $10, $10, 0x00FF
srl $10, $10, 2
# 0b0110110 is char 6
lui $20, 0x3000
sw $10, 4($20)


jr $0
nop
