# Created by car3418
# Should throw
# Return code: 245

lui $4, 0x1000
ori $4, $4, 0x0013
jalr $3 $4
# should throw memory exception -11 = unsigned 245
nop
jr $0
