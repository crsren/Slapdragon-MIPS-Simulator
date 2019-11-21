# Created by nb2618
# testing getc with LB
# Return code: 82
# stdin: R

lui $7, 0x3000

lb $2,  3($7)

jr $0
nop
