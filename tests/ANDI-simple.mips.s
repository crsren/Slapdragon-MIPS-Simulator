# Created by car3418
# Regular anding of two registers
# Return code: 18

ori $2, $2, 0x0013
andi $2, $2, 0x10F2
#  r2 = 0b00010010 = 18

jr $0
