#!/bin/bash

FILES="s_files"
DEST="bin_files"

for FILE in $FILES/*.s
do
	bin/parser $FILE "$DEST/#"
done

echo -e "Finished.\n"
