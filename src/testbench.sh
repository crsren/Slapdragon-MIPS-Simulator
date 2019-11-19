#!/bin/bash


SIMULATOR=$1
TEST_DIR="ttt"

chmod 755 $TEST_DIR/*

function getStatus {
	if [ "$1" == "$2" ] && [ "$3" == "$3" ]
	then
		Status="Pass"
	else
		Status="Fail"
		echo Failed with retcode $1 "->" $2 and stdout $3 "->" $4 "!"
		Error="Retcode ["$1"] expected ["$2"] - Stdout ["$3"] expected ["$4"]."
	fi
}

echo TestID,Instruction,Status,Author,Message > out.csv #clean csv file and write header row

for BIN in $TEST_DIR/*.bin
do

TEST=${BIN%%.*} #remove suffix
TestID=${TEST##*/}

echo "------------------------------------------------------------"
echo $TestID

#run simulator with testcase and redirect stdout and stderr
$SIMULATOR $BIN 1>$TEST.got.stdout 2>$TEST.sim.stderr

#output the stored srdin
cat $TEST.stdin

#capture and store return code
got_RETCODE=$?
echo $got_RETCODE > $TEST.got.retcode

#load references (used in getStatus)
got_STDOUT=$(cat $TEST.got.stdout)
ref_RETCODE=$(cat $TEST.ref.retcode)
ref_STDOUT=$(cat $TEST.ref.stdout)


#define output variables

Instruction=${TestID%%-*}

#check when exactly STATUS is supposed to be FAIL or PASS !!!!!!!!!!!!
getStatus $got_RETCODE $ref_RETCODE $got_STDOUT $ref_STDOUT

#check where we are supposed to get Author from !!!!!!!!!!!!!!
tmp=$(sed -n 1p $TEST.mips.s)
Author=${tmp##*:}

#Message (optional (what went wrong), free form) !!!!!!!!!
tmp=$(sed -n 2p $TEST.mips.s)
Message=${tmp##*#}

echo $TestID","$Instruction","$Status","$Author","$Message";"$Error >> out.csv

done
