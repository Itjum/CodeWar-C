#!/bin/sh

if [ $# -ne 1 ]
then
    exit 1
fi
if [ -r $1 ]
then
    while IFS= read -r l;
    do
        nbcar=${#l}
        if [ $nbcar -ge 80 ]
        then
            printf "%s\n" "$l"
        fi
    done < "$1"
    exit 0
fi
exit 1
