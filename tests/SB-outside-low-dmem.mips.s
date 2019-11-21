# Created by nb2618
# edge case writing outside low dmem
# Return code: 245

lui $4, 0x8000
ori $4, $4, 0x0098

lui $6, 0x2000

sb $4, -1($6)


jr $0
nop
