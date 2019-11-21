# Created by car3418
# Check if branching backwards works
# Return code:

lui $3, 0xFFFF
ori $3, $3, 0xFFFF
ori $2, $2, 5

sub $2, $2, $3
bgez $2, -2
nop
addi $2, $2, 10
# -1 + 10 is 9

jr $0
nop
