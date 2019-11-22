# Created by: nb2618
# Tests DIV for dividing by zero exception
# Retcode: 246

lui     $5, 0x7fff
ori     $5, $5, 0xffff
div     $5, $4
nop
nop


jr      $0
nop
