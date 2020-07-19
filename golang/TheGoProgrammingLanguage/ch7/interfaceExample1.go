package main

import (
	"fmt"
	"os"
)

//ByteCount byte counts
type ByteCount int

func (b *ByteCount) Write(p []byte) (n int, err error) {
	*b += ByteCount(len(p))
	return len(p), nil
}

func main() {
	fmt.Println("123")
	fmt.Fprintf(os.Stderr, "haha %v %v %v\n", 0.5*0.5*0.5*0.5, "hulk", 3.14)
	bytec := ByteCount(123)
	bytec.Write([]byte("123"))
	fmt.Println(bytec)
	fmt.Fprintf(&bytec, "name %s", "haha")
	fmt.Println(bytec)
	fmt.Printf("%T %T\n", bytec, os.Stdout)
}
