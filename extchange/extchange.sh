#!/bin/sh

if [ $# -ne 2 ];
then
    echo "Usage: extchange.sh 'ext1' 'ext2'"
    exit 1
fi

verif=0
var=0

for f in *;
do
    var=${f%.*}.$1
    if [ "$f" = "$var" ]
    then
        verif=1
        mv "${f}" "${f%.*}.$2"
        echo "mv ${f} ${f%.*}.$2"
    fi
done

if [ $verif -ne 0 ]
then
    exit 0
else
    exit 2
fi
