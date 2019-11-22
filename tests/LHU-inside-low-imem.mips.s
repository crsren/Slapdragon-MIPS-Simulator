# Created by nb2618
# loading inside low imem
# Return code: 4

lui $4, 0x8001
ori $4, $4, 0xD469

lui $6, 0x1000

lhu $2, 0($6)

jr $0
nop
