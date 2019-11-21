# Created by nb2618
# testing zero extension
# Return code: 0

lui $4, 0x8000
ori $4, $4, 0xF469

lui $6, 1000
ori $6, $6, 0x0004

sw $4, 0($6)
lhu $2, 3($6)
srl $2, $2, 16



jr $0
nop
