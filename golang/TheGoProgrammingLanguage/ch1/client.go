package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
)

var g_thread_num int

func main() {
	g_thread_num = 2
	url := os.Args[1]
	ch := make(chan string)
	for thread_num := 0; thread_num < g_thread_num; thread_num++ {
		go fetch(url, ch)
	}

	for i := 0; i < g_thread_num; i++ {
		fmt.Fprintf(os.Stdout, "thread[%d] %s\n", i, <-ch)
	}
}

func fetch(url string, ch chan<- string) {
	for i := 0; i < 10000; i++ {
		resp, err := http.Get(url)
		if err != nil {
			fmt.Fprintln(os.Stderr, "http.Get failed url %s ,err %v", url, err)
			return
		}
		io.Copy(os.Stdout, resp.Body)
		resp.Body.Close()
	}
	ch <- fmt.Sprintf("t")
}
