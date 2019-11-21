# Created by nb2618
# checks access to outside low dmem edge
# Return code: 245

lui $7, 0x2000

ori $4, $4, 0x9876

lbu $2,  -1($7)

jr $0
nop
