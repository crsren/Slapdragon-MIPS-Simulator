# Created by nb2618
# checks access to outside high dmem edge
# Return code: 245

lui $7, 0x2400

ori $4, $4, 0x7890

lb $2,  0($7)

jr $0
nop
