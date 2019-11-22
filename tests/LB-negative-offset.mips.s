# Created by nb2618
# loads LB with a negative offset
# Return code: 164

lui $7, 0x2000

lui $10, 0x2000
ori $10, $10, 0x0004

lui $4, 0x89A4

sw $4,  0($7)
lb $2,  -3($10)

jr $0
nop
