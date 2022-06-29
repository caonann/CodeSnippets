package arrary

import "fmt"

func TestStruct() {
	type myTestStruct struct {
		name, address string
		age           int
		pStruct       *myTestStruct
	}

	oMyTest := myTestStruct{
		name:    "hulk",
		address: "shenzhen",
		age:     100,
		pStruct: nil,
	}

	var oMyTest2 myTestStruct
	oMyTest2 = oMyTest
	oMyTest2.pStruct = &oMyTest
	fmt.Printf("oMytest %p,oMytest2 %p\n", &oMyTest, &oMyTest2)
	fmt.Println(oMyTest, oMyTest2, oMyTest2.pStruct.name)

	values := []int{1, 4, 5, 8, 2, 7}
	Sort(values)
	fmt.Println(values)
	arrs := []int{}
	TestFunc(&arrs)
	fmt.Println("test arrs1: ", arrs)

	arrs2 := []int{1, 2, 3}
	fmt.Printf("len %v cap %v\n", len(arrs2), cap(arrs2))
	TestFunc2(arrs2[:0])
	fmt.Println("test arrs2: ", arrs2)

	type Point struct {
		X, Y int
	}
	type Wheel struct {
		Point
		name string
	}

	w := Wheel{Point: Point{X: 1, Y: 2}, name: "hulk"}
	fmt.Printf("%#v %v %v\n", w, w.X, w.name)
	w1 := w
	fmt.Printf("is equal %#v\n", w1 == w)
	w1.name = "hulk2"
	fmt.Printf("is equal %#v\n", w1 == w)
	fmt.Printf("%v,%v\n", w1.name, w.name)
	fmt.Printf("%p,%p\n", &w1.name, &w.name)
}

func TestFunc(values *[]int) {
	for i := 0; i < 10; i++ {
		*values = append(*values, i)
	}
	fmt.Println("Inner TestFunc ", values)
}

func TestFunc2(values []int) {
	values = append(values, 5)
}

type tree struct {
	value  int
	pLeft  *tree
	pRight *tree
}

func Sort(values []int) {
	var root *tree
	for _, value := range values {
		root = add(root, value)
	}
	fmt.Println(root)
	appendValues(root, values[:0])
	fmt.Println(values)
}

func appendValues(pNode *tree, values []int) []int {
	if pNode != nil {
		values = appendValues(pNode.pLeft, values)
		values = append(values, pNode.value)
		values = appendValues(pNode.pRight, values)
	}
	return values
}

func add(pNode *tree, value int) *tree {
	if nil == pNode {
		return &tree{value: value}
	}
	if pNode.value > value {
		pNode.pLeft = add(pNode.pLeft, value)
	} else {
		pNode.pRight = add(pNode.pRight, value)
	}
	return pNode
}
