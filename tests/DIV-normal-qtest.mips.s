# Created by NB696969
# What does this do + retcode
# retcode: 0

lui     v0,0x7fff
ori     v0,v0,0xffff
lui     v1,0x7fff
ori     v1,v1,0xffff
div     $a0,v1
ssl     $zero, $zero, 0
ssl     $zero, $zero, 0
mflo    v0

jr      ra
ssl     $zero, $zero, 0
nop
