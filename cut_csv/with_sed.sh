#!/bin/sh

if [ $# -ne 2 ]
then
    exit 1
fi
num=$2
i=1
while read name
do
    if [ $i -eq $num ];
    then
        echo "$name" | sed 's/.*;\(.*\)\;\(.*\)\;.*;/\1 is \2/'
    fi
    i=$((i + 1))
done < $1
