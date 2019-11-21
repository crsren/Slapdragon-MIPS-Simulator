# Created by nb2618
# loading outside low dmem
# Return code: 245

lui $4, 1222
ori $4, $4, 0x373D

lui $6, 0x2000

lh $2,  0($6)

jr $0
nop
