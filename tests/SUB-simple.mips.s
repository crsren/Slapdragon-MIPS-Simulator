# Created by car3418
# Simple substraction without overflows
# Return code: 236

addi $3, $3, 7
addi $4, $4, 27
sub $2, $3, $4
# -20 is unsigned  236

jr $0
nop
