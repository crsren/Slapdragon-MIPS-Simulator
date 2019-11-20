# Created by car3418
# Check if sign extended
# Return code: 248

lui $8, 0x8000
sra $2, $8, 28
#sign extended so lowest 8 bit: 0b11111000 = 248

jr $0
