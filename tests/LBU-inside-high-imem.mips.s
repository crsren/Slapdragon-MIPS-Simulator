# Created by nb2618
# checks access to inside high imem edge
# Return code: 0

lui $7, 0x1100

ori $4, $4, 0xCDBE

lbu $2,  -1($7)

jr $0
nop
