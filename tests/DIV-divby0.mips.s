#Created by: nb2618
#Tests DIV for dividing by zero exception
# Retcode: 246

lui     $5, 0x7fff
ori     $6, $6, 0xffff
div     $5, $6
nop
nop
mflo    $2

jr      $0
nop
