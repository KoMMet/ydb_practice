#!/bin/sh

bfpflg=0
utlflg=0
udvflg=0
dafflg=0

trap ' 
    echo "input ctrl+c"
    exit
' INT

while getopts "aftdD" option
do
    case $option in
        a)
            bfpflg=1
            utlflg=1
            udvflg=1
            dafflg=1
            ;;
        f)
            bfpflg=1
            ;;
        t)
            utlflg=1
            ;;
        d)
            udvflg=1
            ;;
        D)
            dafflg=1
            ;;
        \?)
            echo "invalid argment"
            exit 1
            ;;
    esac
done

shift $(expr $OPTIND - 1)

if [ $bfpflg -eq 1 ]; then
    cd Bfp
    make clean
    make
    make exec
    cd -
fi

if [ $utlflg -eq 1 ]; then
    cd Utl
    make clean
    make
    make lib
    cd -
fi

if [ $udvflg -eq 1 ]; then
    cd Udv
    make clean
    make
    make lib
    cd -
fi

if [ $dafflg -eq 1 ]; then
    cd Daf
    make clean
    make
    make lib
    cd -
fi
