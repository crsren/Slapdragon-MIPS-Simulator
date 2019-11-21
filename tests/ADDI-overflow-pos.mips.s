# Created by car3418
# Adding pos immediate to pos a pos int with overflow
# Return code: 246

#lui $8, 0x7FFF
ori $8, $0, 0xFFFF

addi $2, $8, 0x0001
#r8 = max pos and immediate = 1 -> signed negative
# Arithmetic exception -10 is 246

jr $0
nop
