package main

import (
	"fmt"
	"sync"
	"time"
)

var cache = struct {
	name    string
	mapping map[string][]int
	sync.Mutex
}{
	mapping: make(map[string][]int),
}

type myclass struct {
	name string
}

func (m *myclass) String() string {
	fmt.Println(m.name)
	return m.name
}

func (m *myclass) SetName(name string) {
	m.name = name
}

var color = struct {
	name string
	myclass
}{
	name: "heihei",
}

func main() {
	cache.Lock()
	for i := 0; i < 10; i++ {
		cache.mapping["hulkcao"] = append(cache.mapping["hulkcao"], i)
	}
	cache.Unlock()

	for _, value := range cache.mapping["hulkcao"] {
		fmt.Println(value)
	}

	color.SetName("haha")
	color.String()

	const day = 24 * time.Hour
	fmt.Println(day.Seconds()) // "86400"
}
