package main

import (
	"fmt"

	"control_flow/init_demo2"
)

func TestSwitch() {
	switch {
	case true:
		fmt.Println("123")
		fallthrough
	case true:
		fmt.Println("456")
	case true:
		fmt.Println("789")
	}
}
func main() {
	fmt.Println("Hello, World!")
	TestSwitch()
	init_demo2.Hello()
}
