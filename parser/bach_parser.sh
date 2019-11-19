#!/bin/bash

FILES="files/*.s"
DEST="bin_files"

for FILE in $FILES
do
    bin/parser $FILE "$DEST/#"
done

echo -e "Finished.\n"
