# Created by car3418
# Check if branches when A != B
# Return code: 8

ori $3, 0x1234
bne $3, $0, 3
# 3 << 2 is 12
nop
jr $0
nop
ori $2, 8
jr $0
nop
