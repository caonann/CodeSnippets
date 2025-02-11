package main // import mytest

import (
	"flag"
	"fmt"
	"simple/arrary"
	"simple/function"
	"simple/strings"
	"simple/variable"
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
	arrary.TestMap()
	arrary.TestSlice2()
	arrary.TestSlice()
	arrary.TestStruct()
}

func runFunctions() {
	ret := function.Fibonacci(5)
	fmt.Printf("fibonacci %v iter %v\n", ret, function.IterationTimes)
}

func runStrings() {
	strings.TestStringSplit()
}
func main() {
	flag.Parse()

	fmt.Println("hello")
	runVariableFuns()
	runArrs()
	runFunctions()
	runStrings()
}
