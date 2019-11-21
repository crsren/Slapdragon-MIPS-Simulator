<<<<<<< HEAD
#Created by: nb2618
#Tests DIV for dividing by zero exception
=======
#Created by: Nikita
#Tests DIV for dividing by zero exception. + retcode
>>>>>>> 7d9ef0a46b540f8edb4a892b40a9907f84c8d487
# Retcode: 246

lui     $5, 0x7fff
ori     $6, $6, 0xffff
div     $5, $6
nop
nop
mflo    $2

<<<<<<< HEAD
jr      $0
=======
jr      $zero
ssl     $zero, $zero, 0
>>>>>>> 7d9ef0a46b540f8edb4a892b40a9907f84c8d487
nop
