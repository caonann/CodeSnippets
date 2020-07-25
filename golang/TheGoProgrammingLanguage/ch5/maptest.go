//map的遍历每次都是随机的
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var tmpmap map[string]string = make(map[string]string)
	for i := 0; i < 10; i++ {
		val := strconv.Itoa(i)
		tmpmap[val] = val
	}
	for key, val := range tmpmap {
		fmt.Printf("key %v,value %v\n", key, val)
	}

}
