# Created by nb2618
# testing getc with LBU
# Return code: 88
# stdin: X

lui $7, 0x3000

lb $2,  3($7)

jr $0
nop
