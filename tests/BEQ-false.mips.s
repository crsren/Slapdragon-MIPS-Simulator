# Created by car3418
# Check if does not branch when A != B
# Return code: 8

ori $3, 0x1234
beq $3, $0, 2
nop
# 2 << 2 is 8
ori $2, 8
jr $0
nop
