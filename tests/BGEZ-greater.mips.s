# Created by car3418
# Check if branches for A > 0
# Return code: 7

ori $3, $3, 1
bgez $3, 4
ori $2, $2, 3
# 4 << 2 is 16
jr $0
nop
nop
ori $2, $2, 5
# 0011 ored 0101 is 0111 is 7
jr $0
nop
