#!/bin/bash

# Check variable
if [ $# -lt 3 ]
then
    echo "Too few variables"
    exit;
fi

FILE_PATH=$1
REPLACE_STR=$2
STR=$3

NUM=```cat $1 | grep -o $2 | grep -c $2```
sed -i "s/$REPLACE_STR/$STR/g" $1
echo "Replace: $NUM"
cat $1
