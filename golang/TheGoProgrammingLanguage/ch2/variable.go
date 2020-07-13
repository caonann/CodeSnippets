package main

import "fmt"

var a string
var b = "abc"
var c string = "efg"
var e, f, g int
var h, i, j = true, "hijk", 1.35

//复杂初始化
var pc [256]byte = func() (pc [256]byte) {
	for i := range pc {
		pc[i] = pc[i]/2 + byte(i&1)
	}
	return
}()

func fib(n int) uint64 {
	var x, y uint64 = 0, 1
	for i := 0; i < n; i++ {
		x, y = y, x+y
	}
	return x
}

func init() {
	fmt.Printf("%v", "init\n")
}

func main() {
	aa := "123"
	bb, cc := 123, "abc"
	bb, ccd := 123, "abc"                           //左侧必须有一个变量未声明过，这是bb:=相当于赋值语句
	bb, cc = 321, "cba"                             //多重赋值
	string_arr := []string{"abc", "def", "hulkcao"} //隐式赋值
	fmt.Printf("%s %d %s %s\n", aa, bb, cc, ccd)
	fmt.Println(fib(10000))
	fmt.Println(string_arr)
	fmt.Println(fib)
}
