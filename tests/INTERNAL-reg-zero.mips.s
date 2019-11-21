# Created by car3418
# Checks if register zero is hard wired
# Return code: 0

addi $0, $0, 1
add $2, $2, $0

jr $0
nop
