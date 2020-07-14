package main

import (
	"fmt"
	"strings"
)

func main() {
	f := square()
	fmt.Println(f())
	fmt.Println(f())
	fmt.Println(square()())
	fmt.Println(square()())
	fmt.Println(strings.Map(func(r rune) rune { return r + 10 }, "hulkcao"))

	closures1 := func() int {
		var x int
		x++
		return x
	}
	fmt.Println(closures1())
	fmt.Println(closures1())
}

func square() func() int {
	var x int
	return func() int {
		x++
		return x * x
	}
}
