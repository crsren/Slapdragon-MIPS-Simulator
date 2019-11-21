# Created by nb2618
# accessing null address LW
# Return code: 245

lui $7, 0x0

lw $2, 0($7)

jr $0
nop
