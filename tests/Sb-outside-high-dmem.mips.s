# Created by nb2618
# edge case writing outside high dmem
# Return code: 245

ori $4, $4, 0x9034

lui $6, 0x24000

sb $4, 0($6)


jr $0
nop
