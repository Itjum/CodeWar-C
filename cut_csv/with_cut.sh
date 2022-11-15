#!/bin/sh

if [ $# -ne 2 ]
then
    exit 1
fi
num=$2
i=1
while IFS=";" read -r col1 col2 col3 col4
do
    if [ $i -eq $num ];
    then
        echo "$col2 is $col3"
    fi
    i=$((i + 1))
done < $1
