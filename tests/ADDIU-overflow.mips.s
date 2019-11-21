# Created by car3418
# Tests that it does not throw exception when dealing with overflow
# Return code: 0

lui $3, 0xFFFF
ori $3, 0xFFFF

addiu $2, $3, 1


jr $0
nop
