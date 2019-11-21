# Created by car3418
# Check if instruction after jump is being executed before branching
# Return code: 3

j 3
ori $2, 1
and $2, 0
addi $2, 1
addi $2, 1

jr $0
nop
