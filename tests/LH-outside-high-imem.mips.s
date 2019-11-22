# Created by nb2618
# loading outside high imem
# Return code: 245

lui $4, 0x8001
ori $4, $4, 0xD469

lui $6, 0x1100

lh $2, 0($6)

jr $0
nop
