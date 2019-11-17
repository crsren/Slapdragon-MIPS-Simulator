#!/bin/bash

chmod 755 ttt/*

SIMULATOR=$1

> out.csv #clean csv file

for i in ttt/ADDU-wrap.mips.bin; do

TEST=${i%%.*}; #remove suffix

$SIMULATOR $i

echo "------------------------------------------------------------"
echo $TEST

#echo $? > $TEST.got.retcode

#echo $1 > $TEST.got.stdout #not sure if this will capture all stdcout

cat $TEST.got.retcode" " >> out.csv
done
