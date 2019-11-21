# Created by car3418
# Check if does not branch for A < 0
# Return code: 3

lui $3, -1
ori $3, -1
bgezal $3, 3
#should not branch
ori $2, 3
lr $0
nop

ori $2, 5
# 0011 ored 0101 is 0111 = 7
jr $0
nop
