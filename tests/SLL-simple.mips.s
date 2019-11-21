# Created by car3418
# Simple shift left
# Return code: 1

lui $3, 0x8000
ssl $2, $3, 31

jr $0
nop
