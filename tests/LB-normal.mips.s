# Created by nb2618
# loads a byte from memory with 0 as MSB
# Return code: 18

lui $7, 0x2000
ori $4, $4, 0x1234

sw $4,  0($7)
lb $2,  2($7)

jr $0
nop
