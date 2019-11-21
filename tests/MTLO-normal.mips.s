# Created by nb2618
# Testing the basic function of MTLO
# Return code: 146

ori $8, $8, 0x3792

mtlo $8

mflo $2

jr $0

nop
