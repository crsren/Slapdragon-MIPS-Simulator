#Created by: Nikita
#Tests DIV for dividing by zero exception. + retcode
# Retcode: 0

lui     $v0,0x7fff
ori     $v0,$v0,0xffff
div     $v0,$v1
ssl     $zero, $zero, 0
ssl     $zero, $zero, 0
mflo    $v0

jr      $zero
ssl     $zero, $zero, 0
