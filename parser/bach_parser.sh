#!/bin/bash

FILES="../tests/*.s"
DEST="../tests"

for FILE in $FILES
do

	tmp=${FILE##*/}
	NAME=${tmp%%.*}

	echo "-----------------------------------"
	echo $NAME

	bin/parser $FILE "$DEST/#"

	#so that we dont have to create extra files for retcode, stdout and stdin
	RetCodeLine=$(grep "code" $FILE)
	RETCODE=${RetCodeLine##*": "}
	echo $RETCODE > $DEST/$NAME.ref.retcode
	StdoutLine=$(grep "tdout" $FILE)
	STDOUT=${StdoutLine##*": "}
	echo $STDOUT > $DEST/$NAME.ref.stdout
	StdinLine=$(grep "tdin" $FILE)
	STDIN=${StdinLine##*": "}
	echo $STDIN > $DEST/$NAME.stdin

done

echo -e "Finished.\n"

rm ../tests/J-delay.mips.bin
rm ../tests/INTERNAL-invalid-instruction.mips.bin
cp ../../J-delay.mips.bin ../tests/J-delay.mips.bin
cp ../../INTERNAL-invalid-instruction.mips.bin ../tests/INTERNAL-invalid-instruction.mips.bin
