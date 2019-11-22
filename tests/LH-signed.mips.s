# Created by nb2618
# testing sign extension for LH
# Return code: 255

lui $4, 0x8000
ori $4, $4, 0xF469

lui $6, 0x2000
ori $6, $6, 0x0004

sw $4, 0($6)
lh $2, 2($6)
srl $2, $2, 16



jr $0
nop
