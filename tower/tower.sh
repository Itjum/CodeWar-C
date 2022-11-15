#!/bin/sh

form=$2
times=$1
if [ "$form" != "triangle" ] && [ "$form" != "square" ]
then
    exit 1
fi

if [ $1 -lt 0 ]
then
    exit 1
else
    echo " _________________"
    while [ $times -gt 0 ]; do
        if [ "$form" = "square" ]
        then
            echo "|  ___       ___  |"
            echo "| |_|_|     |_|_| |"
            echo "| |_|_|     |_|_| |"
            echo "|                 |"
        elif [ "$form" = "triangle" ]
        then
            echo "|                 |"
            echo "|   /\       /\   |"
            echo "|  /__\     /__\  |"
            echo "|                 |"
        else
            exit 1
        fi
        times=$((times - 1))
    done
    echo "|        _        |"
    echo "|       | |       |"
    echo "|       | |       |"
    echo "|_______| |_______|"
fi
