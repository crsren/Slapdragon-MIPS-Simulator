# Created by nb2618
# checks access to outside low imem edge
# Return code: 245

lui $7, 0x1000

lui $4, 0x89A4

lb $2,  -1($7)

jr $0
nop
