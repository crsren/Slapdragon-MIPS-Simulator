# Created by car3418
# Simple shift left
# Return code: 1

ori $3, $3, 0x0001
sll $3, $3, 31
srl $2, $3, 31

jr $0
nop
