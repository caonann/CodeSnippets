#!/bin/bash

<<'COMMENT'
if、elif会执行它后面跟着的命令，然后看返回值是否为0，如果为0则执行then下面的语句块，否则执行else下面的语句块。
true、false事实上也为一个命令，true的返回码必为0，false的返回码必为1
COMMENT

if true
then
    echo "Hello World"
else
    echo "Bug"
fi

if false
then
    echo "Hello World"
elif true
then
    echo "Bug"
else
    echo "Bee"
fi


[ 1 -eq 2 ] || echo "firsh block";echo "second block"

#子shell，退出不能真正运行
[ 1 -eq 1 ] || (echo "firsh blocka";echo "second blocka";exit 1) 

echo "hello"

red_nl_text() { printf "\n\e[31m$1\e[39m\n"; }
terminate_with_msg() { red_nl_text "ERROR: $1"; exit 1; }
[ 1 -eq 2 ] || terminate_with_msg "i will exit"
echo "hh"