# Created by car3418
# Check if simulator terminates when jal to jr r0
# Return code: 3

jal function
addi $2, $2, 3
nop
and $2, $2, $0
jr $0

function: jr $0
jr $31
nop
