# Created by car3418
# Check if two consecutive jumps work
# Return code: 12

j 3
j 4
and $2, 0
addi $2, 1
addi $2, 10
addi $2, 1

jr $0
nop
