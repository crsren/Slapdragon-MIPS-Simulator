# Created by nb2618
# Testing the basic function of MTHI
# Return code: 220

ori $8, $8, 0x28DC

mthi $8

mfhi $2

jr $0

nop
