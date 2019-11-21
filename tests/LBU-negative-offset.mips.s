# Created by nb2618
# loads LBU with a negative offset
# Return code: 18

lui $7, 0x1000

lui $10, 0x1000
ori $10, $10, 0x0004

lui $4, 0x89A4
ori $4, $4, 0x1234


sw $4,  0($7)
lb $2,  -2($10)

jr $0
nop
