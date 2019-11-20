# Created by car3418
# Check if simple shift works
# Return code: 8

lui $8, 0x8000
sra $2, $8, 28
#logical so lowest 8 bit: 0b00001000 = 8

jr $0
