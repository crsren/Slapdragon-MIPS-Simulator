#!/bin/bash

EXIT_STATUS = $?
TEST = $("ADDU-wrap") #$1
SIMULATOR = $("mips_simulator")
#later the input $1 will be the name of the simulator and the tests wil be predefined (?)

echo ./bin/$(SIMULATOR) ./testsThomas/$(TEST).mips.bin
