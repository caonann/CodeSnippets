package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"sync"
	"time"
)

const (
	concurrentRequests = 600
	url                = "http://localhost:8000/benchmark"
)

func process() {
	var wg sync.WaitGroup
	start := time.Now()
	for i := 0; i < concurrentRequests; i++ {
		wg.Add(1)

		go func() {
			defer wg.Done()

			resp, err := http.Get(url)
			if err != nil {
				fmt.Println("Error:", err)
				return
			}
			defer resp.Body.Close()

			body, err := ioutil.ReadAll(resp.Body)
			if err != nil {
				fmt.Println("Error:", err)
				return
			}

			fmt.Println("Response:", string(body))
		}()
	}

	wg.Wait()
	elapsed := time.Since(start)
	fmt.Println("Elapsed time:", elapsed)
}
func main() {
	for i := 0; i < 100; i++ {
		process()
	}
	fmt.Println("Done")
}
