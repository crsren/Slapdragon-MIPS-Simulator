# Created by car3418
# Check if return link works
# Return code: 111


jal function
ori $2, $2, 10
addi $2, $2, 100
jr $0
nop

function: addi $2, $2, 1
jr $31
nop
