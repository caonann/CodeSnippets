package main

import (
	"arrary"
	"flag"
	"fmt"
	"variable"
)

var n = flag.Bool("n", false, "omit trailing newline")
var sep = flag.String("s", " ", "separator")

func runVariableFuns() {
	variable.TestVariable()
	variable.TestInt()
	variable.TestString()
	variable.TestPtr()
}

func runArrs() {
	arrary.TestArr()
	arrary.TestSlice()
}
func main() {
	flag.Parse()

	fmt.Println("hello")
	runVariableFuns()
	runArrs()
}
