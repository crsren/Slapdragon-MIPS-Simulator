# Created by car3418
# Check if branches and links for A < 0
# Return code: 8

lui $3, 0x8000
bltzal $3, 3
# 3 << 2 = 12
ori $2, $2, 3
addi $2, $2, 1
jr $0
nop
ori $2, $2, 5
# 0011 ored 0101 is 0111 = 7
jr $31
nop
