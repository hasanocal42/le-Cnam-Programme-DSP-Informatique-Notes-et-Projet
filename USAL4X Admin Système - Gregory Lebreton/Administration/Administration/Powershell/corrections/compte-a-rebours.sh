#!/bin/bash
nombre=10
while [ $nombre -ge 0 ]
do
    echo $nombre

    if [ $nombre = 0 ]
    then
        echo "BOOM!"
    fi

    let "nombre=nombre-1"
done

### UNTIL
nombre=10
until [ $nombre = -1 ]
do
    echo $nombre

    if [ $nombre = 0 ]
    then
        echo "BOOM!"
    fi
    
    let "nombre=nombre-1"
done  