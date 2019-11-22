# Created by nb2618
# Testing normal functioning
# Return code: 52

lui $4, 0x8000
ori $4, $4, 0xBC34

lui $6, 0x2000
ori $6, $6, 0x0004

sw $4, 0($6)
lhu $2, 2($6)

jr $0
nop
