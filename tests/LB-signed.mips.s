# Created by nb2618
# loads a byte from memory with 1 as MSB
# Return code: 255

lui $7, 0x1000
ori $4, $4, 0xF434

ori $10, $10, 0x0008

sw $4,  0($7)
lb $2,  2($7)
sra $2, $2, 8

jr $0
nop
