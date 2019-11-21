# Created by car3418
# Check for positive integer
# Return code: 3

ori $8, $8, 0xFFE3
# 5 loweset bits are 00011 so shift by 3
ori $9, $9, 0x001B

# 11011 becomes 00011
srav $2, $9, $8


jr $0
nop
