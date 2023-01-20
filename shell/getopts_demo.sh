#!/bin/bash

echo original parameters=["$*"]
echo original OPTIND=[$OPTIND]
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo "[-c :build client demo]  [-s :bulid server demo] [-w :use wbl log]"
echo "[-r :release verision]  [-d :debug verision] [-v :open complie log]"
echo "[-o :use openssl1.0.2]  [-p :use sctp datachannel]"
echo "[-u :enable udpchannel to build in demo -client_demo_udpchannel.cpp]"
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"

while getopts ":a:bc" opt
do
    case $opt in
        a)
            echo "this is -a option. OPTARG=[$OPTARG] OPTIND=[$OPTIND]"
            ;;
        b)
            echo "this is -b option. OPTARG=[$OPTARG] OPTIND=[$OPTIND]"
            ;;
        c)
            echo "this is -c option. OPTARG=[$OPTARG] OPTIND=[$OPTIND]"
            ;;
        ?)
            echo "there is unrecognized parameter."
            exit 1
            ;;
    esac
done
#通过shift $(($OPTIND - 1))的处理，$*中就只保留了除去选项内容的参数，
#可以在后面的shell程序中进行处理
shift $((OPTIND - 1))

echo remaining parameters=["$*"]
echo \$1=["$1"]
echo \$2=["$2"]
