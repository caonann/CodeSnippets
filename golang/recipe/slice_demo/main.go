package main

import "fmt"

func main() {
	var buffer [][]byte
	fmt.Println(len(buffer))
	for i := 0; i < 100; i++ {
		buffer = append(buffer, []byte{})
		if len(buffer) >= 10 {
			fmt.Println(len(buffer))
			buffer = buffer[:0]
		}
	}

}
