lui     v0,0x7fff
ori     v0,v0,0xffff
div     $a0,v1
ssl     $zero, $zero, 0
ssl     $zero, $zero, 0
mflo    v0

jr      ra
ssl     $zero, $zero, 0


0x3C027FFF
0x3442FFFF
0x0043001A
0x00000000
0x00000000
0x00001012
0x03E00008
0x00000000

3C027FFF3442FFFF0043001A00000000000000000000101203E0000800000000
