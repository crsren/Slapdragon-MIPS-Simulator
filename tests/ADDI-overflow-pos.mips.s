# Created by car3418
# Adding pos immediate to a pos int with overflow
# Return code: 246

lui $8, 0x7FFF
ori $8, $8, 0xFFFF

addi $2, $8, 1
# 0x7fff + 1 = 0x8000
# Arithmetic exception -10 is 246

jr $0
nop
