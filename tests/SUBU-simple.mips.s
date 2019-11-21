# Created by car3418
# Checks if subs does normal substraction
# Returncode: 251

ori $8, 10
ori $9, 5

subu $2, $9, $8
# 5 - 10 is -5 = unsigned 251


jr $0
nop
