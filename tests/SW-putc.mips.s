# Created by nb2618
# loading outside of the allowed memory
# Return code: 0
# stdout: $

lui $4, 0x8000
ori $4, $4, 0x4524

lui $6, 0x3000

sw $4, 4($6)

jr $0
nop
nop
