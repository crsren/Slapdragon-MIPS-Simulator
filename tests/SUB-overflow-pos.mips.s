# Created by car3418
# Checking for overflow +A - (-B)
# Return code: 246

lui $2, 0x7FFF
ori $2, $2, 0xFFFF
lui $3, 0xFFFF
ori $3, $3, 0xFFFF
# - -1 = +1

sub $8, $2, $3
#arithmetic overflow -10 is unsigned 246

jr $0
nop
