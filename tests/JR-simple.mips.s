# Created by car3418
# Checks if jr to r0 works
# Return code: 28

jr $0
addi $2, $2, 5
jalr $3, $0
nop
nop
