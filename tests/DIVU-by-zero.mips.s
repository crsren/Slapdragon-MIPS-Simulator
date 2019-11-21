# Created by car3418
# Checks if arithmetic exception is thrown when dividing by zero
# Return code: 246

lui $8, 0x00BC
addi $8, 0x614E
#r8 = 12345678
lui $9, 0

divu $8, $9
# -10 = 246

jr $0
nop
