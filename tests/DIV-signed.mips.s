# Created by nb2618
# Signed division
# retcode: 250
# stdout: 254

lui     $4, 0xffff
ori     $4, $4, 0xffec # -20
ori     $20, $20, 0x0003 # 3
div     $4, $20
nop
nop
mflo    $2
mfhi    $10

lui     $5, 0x3000


sw      $10, 4($5)

jr      $0
nop
