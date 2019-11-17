#!/bin/bash

chmod 755 ttt/*

SIMULATOR=$1

function getStatus {
	if [ $1 == $2 ] && [ $3 == $3 ]
	then
		Status="Pass"
	else
		Status="Fail"
		echo "!!!" Failed with retcode $1 "->" $2 and stdout $3 "->" $4 "!!!"
	fi
}

echo TestID,Instruction,Status,Author,Message > out.csv #clean csv file and write header row

for i in ttt/*.bin
do

TEST=${i%%.*} #remove suffix

echo "------------------------------------------------------------"

#run simulator with testcase
$SIMULATOR $i

#store return code and stdout
got_RETCODE=$?
got_STDOUT=$1 #not sure if this will capture all of stdout
$got_RETCODE > $TEST.got.retcode
$got_STDOUT > $TEST.got.stdout

#load references
ref_RETCODE=$(cat $TEST.ref.retcode)
ref_STDOUT=$(cat $TEST.ref.stdout)

#define output variables
TestID=${TEST##*/}
Instruction=${TestID%%-*}
#check when exactly STATUS is supposed to be FAIL or PASS !!!!!!!!!!!!
getStatus $got_RETCODE $ref_RETCODE $got_STDOUT $ref_STDOUT

#check where we are supposed to get Author from !!!!!!!!!!!!!!
Author="Slapdragon"
#Message (optional (what went wrong), free form) !!!!!!!!!
Message="-"

echo $TestID","$Instruction","$Status","$Author","$Message >> out.csv

done
