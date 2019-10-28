#!/bin/bash

./bin/simulator
EXIT_STATUS = $?

if [ $EXIT_STATUS -e 0]; then
    echo "Succeeded";
else
    echo "Failed";
    # catch different exit cases
fi
