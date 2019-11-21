# Created by nb2618
# edge case writing to 0x0
# Return code: 245

ori $4, $4, 0x9034

lui $6, 0x0

sb $4, 0($6)


jr $0
nop
