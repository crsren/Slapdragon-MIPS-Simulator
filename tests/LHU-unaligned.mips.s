# Created by nb2618
# testing unaligned 
# Return code: 245

lui $4, 0x8000
ori $4, $4, 0xD469

lui $6, 0x2000
ori $6, $6, 0x0004

sw $4, 0($6)
lhu $2, 3($6)



jr $0
nop
