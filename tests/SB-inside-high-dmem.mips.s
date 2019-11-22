# Created by nb2618
# edge case writing inside high dmem
# Return code: 120

lui $4, 0x8000
ori $4, $4, 0x87878

lui $6, 0x2400

sb $4, -1($6)

lw $2, -4($6)


jr $0
nop
