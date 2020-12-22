package arrary

import (
	"fmt"
	"sort"
	"strconv"
)

func TestMap() {
	ages := map[string]int{
		"a": 1,
		"b": 2,
	}

	ages["cc"] = 3
	delete(ages, "a")
	delete(ages, "aa")

	pages := make(map[string]int)
	pages = ages
	pages["cc"]++

	for i := 0; i < 20; i++ {
		pages[strconv.Itoa(i)] = i
	}

	//var names []string
	names := make([]string, 0, len(pages))
	for name, age := range ages {
		fmt.Printf("age %v,name %v\n", age, name)
		//输出是随机的
		names = append(names, name)
	}

	//sort
	sort.Strings(names)
	for _, name := range names {
		fmt.Printf("age %v,name %v\n", pages[name], name)
	}

	var maptest map[string]int
	fmt.Println(maptest == nil)
	fmt.Println(len(maptest))
	maptest = pages
	fmt.Println(len(maptest))

	if age, ok := maptest["hulk"]; !ok {
		fmt.Println("can not find key")
	} else {
		fmt.Println("find age ", age)
	}

	maptest2 := map[int]int{
		1: 1,
		2: 2,
	}
	maptest3 := maptest2
	maptest3[3] = 3
	fmt.Printf("%p,%p\n", maptest2, maptest3)
	maptest4 := map[int]int{
		5: 5,
	}

	isOk := isEqual(maptest3, maptest4)
	if isOk {
		fmt.Println("is Equal")
	} else {
		fmt.Println("is Not Equal")
	}

	key := generateKey(names)
	fmt.Println("key is", key)
	maptest[key] = 2
	fmt.Println(maptest)
}

func isEqual(x, y map[int]int) bool {
	if len(x) != len(y) {
		return false
	}
	for key, value := range x {
		if v, ok := y[key]; !ok || v != value {
			return false
		}
	}
	return true
}

func generateKey(list []string) string {
	return fmt.Sprintf("%q", list)
}
