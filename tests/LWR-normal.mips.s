# Created by nb2618
# normal operation test
# Return code: 187
# stdout: [

lui $7, 0x2000

lui $4, 0x5BBB
ori $4, $4, 0x7843

lui $10, 0x3000

sw $4,  0($7)
lwr $2,  1($7)
srl $4, $2, 8
sb $4, 7($10)

jr $0
nop
