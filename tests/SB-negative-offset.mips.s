# Created by nb2618
# Testing negative offset function of SB
# Return code: 32

ori $4, $4, 0xD420

lui $6, 0x2000
ori $6, $6, 0x0004

lui $7, 0x2000

sb $4, -1($6)

lw $2, 0($7)


jr $0
nop
