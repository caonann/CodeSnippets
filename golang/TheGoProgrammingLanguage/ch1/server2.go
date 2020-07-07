package main

import (
	"fmt"
	"log"
	"net/http"
	"sync"
)

var g_count int
var mu sync.Mutex

func main() {
	http.HandleFunc("/", handler)
	http.HandleFunc("/counter", counter)
	log.Fatal(http.ListenAndServe("localhost:8080", nil))
}

func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "URL.PATH=%q\n", r.URL.Path)
	mu.Lock()
	g_count++
	mu.Unlock()
}

func counter(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "count %d\n", g_count)
}
