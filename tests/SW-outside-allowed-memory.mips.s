# Created by nb2618
# loading outside of the allowed memory
# Return code: 245

lui $4, 0x8000
ori $4, $4, 0x4567

lui $6, 0x2000
ori $6, $6, 0x0000

sw $4, -4($6)

lb $2, 7($6)

jr $0
nop
nop
