# Created by nb2618
# negative offset in SW checking sign extension
# Return code: 103

lui $4, 0x8000
ori $4, $4, 0x4567

lui $6, 0x2000
ori $6, $6, 0x0008

lui $7, 0x2000
ori $7, $7, 0x0000

sw $4, -4($6)

lb $2, 7($7)

jr $0
nop
