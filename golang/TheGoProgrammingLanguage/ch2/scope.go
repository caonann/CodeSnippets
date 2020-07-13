package main

import (
	"fmt"
	"os"
)

var cwd string

func init() {
	var err error
	cwd, err = os.Getwd()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error: %v\n", err)
		os.Exit(1)
	}
	fmt.Println(cwd)
}

func main() {
	x := "123456"
	for i := 0; i < len(x); i++ {
		x := x[i]
		fmt.Printf("%v,%[1]c,%[1]s\n", x)
	}
	fmt.Printf("gloable cwd [%s]\n", cwd)
}
