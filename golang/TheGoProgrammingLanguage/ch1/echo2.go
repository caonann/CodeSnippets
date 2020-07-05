package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	s, sep := "", ""
	for _, arg := range os.Args[0:] { // _ 空标识符，用于任何语法需要变量名但程序逻辑不需要的时候
		s += sep + arg
		sep = " "
	}

	for index, arg := range os.Args[0:] { //go规定变量声明必须被使用，range 默认都会有一个索引对应一个值
		s += sep + ":" + arg
		sep = " "
		fmt.Println(index)
	}
	fmt.Println(s)
	fmt.Println(strings.Join(os.Args[1:], "#"))
	fmt.Println(os.Args[1:])
}
