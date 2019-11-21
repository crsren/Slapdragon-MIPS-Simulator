# Created by nb2618
# Writing to imem error expected
# Return code: 245

lui $4, 0x8000
ori $4, $4, 0xD473

lui $6, 0x1000

sb $4, 4($6)

jr $0
nop
