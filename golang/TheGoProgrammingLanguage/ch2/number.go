package main

import "fmt"

func main() {
	var ouint uint64 = 0666
	fmt.Printf("%d,%[1]o,%#[1]o\n", ouint)
	binary_numbers := 00101
	binary_numbers1 := 00110
	fmt.Printf("%08b\n", binary_numbers&binary_numbers1)
	fmt.Printf("%d\n", 2e2)
}
