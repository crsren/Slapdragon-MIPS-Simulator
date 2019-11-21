# Created by car3418
# Check if does not branch for A = 0
# Return code: 3

bltz $0, 4
ori $2, 3
# 4 << 2 = 16
lr $0
nop
nop
ori $2, 5
# 0011 ored 0101 is 0111 = 7
jr $0
nop
