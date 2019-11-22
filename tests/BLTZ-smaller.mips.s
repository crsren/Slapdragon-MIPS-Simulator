# Created by car3418
# Check if branches for A < 0
# Return code: 7

lui $3, $3, 0xFFFF
ori $3, $3, 0xFFFF
bltz $3, 3
ori $2, $2, 3
# 3 << 2 = 12
jr $0
nop
ori $2, $2, 5
# 0011 ored 0101 is 0111 = 7
jr $0
nop
