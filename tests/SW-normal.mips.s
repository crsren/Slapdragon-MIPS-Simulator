# Created by nb2618
# Testing normal function of SW
# Return code: 103

lui $4, 0x8000
ori $4, $4, 0x4567

lui $6, 0x2000

sw $4, 4($6)

lb $2, 7($6)

add $2, $8, $9

jr $0
