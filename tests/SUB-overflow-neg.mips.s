# Created by car3418
# Checking for overflow -A - (+B)
# Return code: 246

lui $2, 0x8000
lui $3, 1
# r3 signed is 0xFFFF

sub $8, $2, $3
#arithmetic overflow -10 = unsigned 246

jr $0
nop
