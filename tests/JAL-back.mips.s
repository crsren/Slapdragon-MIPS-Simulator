# Created by car3418
# Check if return link works
# Return code: 121


jal 5
ori $2, 10
addi $2, 100
j $0
nop
addi $2, 1
j $31
nop

and $2, 0
j $0
nop
