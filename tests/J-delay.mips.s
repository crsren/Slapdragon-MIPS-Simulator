# Created by car3418
# Check if instruction after jump is being executed before branching
# Return code: 3

j 5
addi $2, $2, 21
addi $2, $2, 69
addi $2, $2, 420
addi $2, $2, 666
addi $2, $2, 19

jr $0
nop
