# Created by car3418
# Checks if subs does normal substraction
# Returncode: 251

ori $8, $8, 10
ori $7, $7, 5

subu $2, $7, $8
# 5 - 10 is -5 is unsigned 251

jr $0
nop
