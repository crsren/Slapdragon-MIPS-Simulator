# Created by nb2618
# Testing normal functioning of LH
# Return code: 105

lui $4, 0x8000
ori $4, $4, 0xD469

lui $6, 0x2000
ori $6, $6, 0x0004

sw $4, 0($6)
lh $2, 2($6)

jr $0
nop
