# Created by nb2618
# checks access to outside high imem edge
# Return code: 245

lui $7, 0x1100

ori $4, $4, 0x9876

lb $2,   0($7)

jr $0
nop
