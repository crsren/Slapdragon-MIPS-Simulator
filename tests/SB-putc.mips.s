# Created by nb2618
# Testing putc feature of SB
# Return code: 115
# stdout: i

lui $4, 0x8000
ori $4, $4, 0xD469

lui $6, 0x2000
ori $6, $6, 0x0004


sb $4, 3($6)



jr $0
nop
