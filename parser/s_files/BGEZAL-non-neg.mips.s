# Created by Christoph
# Tests BGEZAL on a non-negative source1
# Return code = 255
# stdout = 10


lui $v0, 0xFFFF
ori $v0, 0xFFFF

jr $zero
ssl $zero, $zero, 0
