# Created by car3418
# Check if next instruction is executed twice
# Return code: 20

j 1
# 1 << 2 = 4
addi $2, $2, 10

jr $0
nop
