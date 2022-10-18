package main

import "fmt"

func main() {
	done := make(chan struct{})
	for i := 0; i < 2; i++ {
		go mainThread(done)
	}
	for i := 0; i < 2; i++ {
		<-done
		fmt.Println("done")
	}

}
