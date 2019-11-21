# Created by car3418
# Check if branches for A > 0
# Return code: 7

ori $3, 1
bgtz $3, 3
# 3 << 2 = 12
ori $2, 3
lr $0
nop
ori $2, 5
# 0011 ored 0101 is 0111 = 7
jr $0
nop
