package main

import "fmt"

func main() {
	ret := func(x int) int {
		x++
		return x
	}(123)
	fmt.Println(ret)
}
