# Created by nb2618
# loading outside high dmem
# Return code: 245

lui $4, 0x1DC0
ori $4, $4, 0xDE99

lui $6, 0x2400

lh $2,  0($6)

jr $0
nop
