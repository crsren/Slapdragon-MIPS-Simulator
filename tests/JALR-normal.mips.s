# Created by car3418
# Checks if jumping to right address
# Return code: 28

lui $4, 0x1000
ori $4, 0x001C
# jump to 7th instruction
jalr $3 $4
nop
jr $0
nop
or $2, $4
jr $31
