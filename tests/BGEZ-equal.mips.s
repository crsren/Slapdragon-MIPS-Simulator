# Created by car3418
# Check if branches for A = 0
# Return code: 7

bgez $2, 4
# 4 << 2 = 16
ori $2, $2, 3
jr $0
nop
nop
ori $2, $2, 5
# 0011 ored 0101 is 0111 = 7
jr $0
nop
