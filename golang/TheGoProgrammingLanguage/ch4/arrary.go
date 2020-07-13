package main

import "fmt"

type point struct {
	X int
	Y int
}

type person struct {
	enName string
	age    int32
}

type node struct {
	value int64
	name  string
	point
	person
}

func main() {
	arr := [...]int{1, 2, 3, 4}
	var nodeArray []*node
	for i := 0; i < 5; i++ {
		nodeArray = append(nodeArray, &node{value: 123, name: "hulkcao"})
	}
	for _, node := range nodeArray {
		fmt.Println(arr, node)
	}
	myNode := node{value: 123, point: point{X: 456}}

	fmt.Println(myNode.X)

}
