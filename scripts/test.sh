#!/bin/bash
NETWORK_INTERFACE=$1
LOGFILENAME=$2

# Check variable
if [ $# -lt 2 ]
then
    echo "Too few variables"
    exit;
fi

rm -f $LOGFILENAME
sudo build/main $NETWORK_INTERFACE >> $LOGFILENAME