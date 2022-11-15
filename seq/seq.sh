#!/bin/sh

if [ "$#" -ne 3 ];
then
    echo "Usage: ./seq.sh FIRST INCREMENT LAST" >>/dev/stderr
    exit 1
else
    num1=$1
    crement=$2
    num2=$3
    if [ $num2 -gt $num1 ];
    then
        if [ $crement -le 0 ];
        then
            exit 1
        fi
        while [ $num1 -le $num2 ]; do
            echo "$num1"
            num1=$(($num1 + $crement))
        done
    elif [ $num2 -lt $num1 ];
    then
        if [ $crement -ge 0 ];
        then
            exit 1
        fi
        while [ $num1 -ge $num2 ]; do
            echo "$num1"
            num1=$(($num1 + $crement))
        done
    else    
        echo "$num1"
    fi
fi 
