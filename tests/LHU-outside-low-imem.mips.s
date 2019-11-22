# Created by nb2618
# loading outside low imem
# Return code: 245

lui $4, 0x8001
ori $4, $4, 0xD469

lui $6, 0x1000

lhu $2, -2($6)

jr $0
nop
