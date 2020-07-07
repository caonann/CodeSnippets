package main

import "fmt"

func main() {
	var a int = 1
	p := &a
	var p1 = &a
	*p1 = 3
	*p = 2
	fmt.Println(*p)
	pf := fpointer()
	fmt.Println(*pf)
	*pf = 2
	fmt.Println(*pf)
}

func fpointer() *int {
	v := 123
	return &v
}
