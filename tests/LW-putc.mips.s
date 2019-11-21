# Created by nb2618
# trying to access PUTC LW
# Return code: 245

lui $7, 0x3000
ori $4, $4, 0x5678

lw $2, 4($7)

jr $0
nop
