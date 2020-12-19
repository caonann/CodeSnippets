package main

import (
	"flag"
	"fmt"
	"variable"
)

var n = flag.Bool("n", false, "omit trailing newline")
var sep = flag.String("s", " ", "separator")

func main() {
	flag.Parse()

	fmt.Println("hello")
	variable.TestVariable()
	variable.TestInt()
}
