# Created by car3418
# Check if simulator terminates when jal to jr r0
# Return code: 3

jal 4
addi r2, 3
and $2, 0
jr $0

jr $0
jr $31
nop
