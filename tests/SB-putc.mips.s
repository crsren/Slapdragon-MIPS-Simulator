# Created by nb2618
# Testing putc feature
# Return code: 0
# stdout: i

lui $4, 0x8000
ori $4, $4, 0xD469

lui $6, 0x3000
ori $6, $6, 0x0004


sb $4, 3($6)



jr $0
nop
