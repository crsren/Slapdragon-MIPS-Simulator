# Created by car3418
# Check if branchs and links for A > 0
# Return code: 7

ori $3, 0xFFFF
bgezal $3, 4
# 4 << 2 = 16
ori $2, 3
addi $2, $2, 1
lr $0
nop
ori $2, 5
# 0011 ored 0101 is 0111 = 7
jr $31
nop
