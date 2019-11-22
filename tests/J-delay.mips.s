# Created by car3418
# Check if instruction after jump is being executed before branching
# Return code: 19

j 4
ori $2, $2, 10
jr $0
nop

addi $2, $2, 9
jr $0
nop

0x08000004
0x3442000A
0x00000008
0x00000000
0x20420009
0x00000008
0x00000000

080000043442000A0000000800000000204200090000000800000000
