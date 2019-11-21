# Created by nb2618
# memory error test when loading a non aligned address LW
# Return code: 245

lui $4, 0xF670
ori $4, $4, 0x0005

lui $7, 0x2000

sw $4, 0($6)

lw $2, 2($6)

jr $0
nop
