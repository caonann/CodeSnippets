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