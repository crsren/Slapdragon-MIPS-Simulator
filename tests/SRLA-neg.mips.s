# Created by car3418
# Check for negative integer being shifted
# Return code: 251

ori $8, $8, 0xFFE3
# 5 loweset bits are 00011 so shift by 3
lui $9, $9, 0xFFFF
ori $9, $9, 0xFFDF

# 11011 is -4 = unsigned 251
srla $2, $9, $8


jr $0
