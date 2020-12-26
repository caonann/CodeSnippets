package arrary

import (
	"bytes"
	"fmt"
)

func TestSlice() {
	weeks := [...]string{1: "mon", "tus", "wed", "thu", "fri", "sat", "sun"}
	fmt.Println(weeks[1:3])
	tmp1 := weeks[1:5]
	tmp2 := weeks[2:4]
	fmt.Printf("tmp1 cap %v,len %v\n", cap(tmp1), len(tmp1))
	fmt.Printf("tmp2 cap %v,len %v\n", cap(tmp2), len(tmp2))
	for _, i := range tmp1 {
		for _, j := range tmp2 {
			if i == j {
				fmt.Println("Is same ", i, j)
				fmt.Printf("address %x,%x\n", &i, &j)
			}
		}
	}

	//共享变量，地址相同
	for i := 0; i < len(tmp1); i++ {
		for j := 0; j < len(tmp2); j++ {
			if tmp1[i] == tmp2[j] {
				fmt.Printf("real address %x,%x\n", &tmp1[i], &tmp2[j])
			}
		}
	}

	intarr := [...]int{1, 2, 3, 4, 5, 6}

	reserve(intarr[:2])
	reserve(intarr[2:])
	reserve(intarr[:])
	fmt.Println(intarr)

	arr1 := []byte{1, 2, 3, 4}
	arr2 := []byte{4, 2, 1}
	fmt.Println("arr1 == arr2 ", bytes.Equal(arr1, arr2))

	var arr3 []int
	arr3 = appendInt(arr3, 1)
	arr3 = appendInt(arr3, 2)
	arr3 = appendInt(arr3, 3)
	fmt.Println("appendInt ", arr3)

	var runes []rune
	for _, r := range "hello hulk" {
		runes = append(runes, r)
	}

	runes = append(runes, 'a', 'b')
	fmt.Println(runes)

	strings := []string{"hulk", "", "haha"}
	ret := func(strings []string) []string {
		out := strings[:0] // zero-length slice of original
		for _, s := range strings {
			if s != "" {
				out = append(out, s)
			}
		}
		return out
	}(strings)
	fmt.Println("slice ret is ", ret)
	fmt.Println("strings is ", strings)
	func(strings []string) {
		strings = append(strings, "test1", "test2")
	}(strings[:0]) //指针重置为0，不会触发重新分配内存,所以不会有问题
	fmt.Println("strings2 is ", strings)
	//这两种实际上是一种类型，相当于把指针重置了
	fmt.Printf("%T,%T\n", strings, strings[:0])
}

func TestSlice2() {
	//https://medium.com/swlh/golang-tips-why-pointers-to-slices-are-useful-and-how-ignoring-them-can-lead-to-tricky-bugs-cac90f72e77b
	fmt.Println("TEST CASE 1")
	slice := []string{"a", "a"}
	func(slice []string) {
		slice[0] = "b"
		slice[1] = "b"
		fmt.Println(slice)
	}(slice)
	fmt.Println(slice)

	fmt.Println("TEST CASE 2")
	slice = []string{"a", "a"}
	func(slice *[]string) {
		(*slice)[0] = "b"
		(*slice)[1] = "b"
		fmt.Println(*slice)
	}(&slice)
	fmt.Println(slice)

	fmt.Println("TEST CASE 3")
	slice = []string{"a", "a"}

	func(slice []string) {
		slice = append(slice, "a")
		slice[0] = "b"
		slice[1] = "b"
		fmt.Println(slice)
	}(slice)
	fmt.Println(slice)

	fmt.Println("TEST CASE 4")
	slice = []string{"a", "a"}

	func(slice []string) {
		slice[0] = "b"
		slice[1] = "b"
		slice = append(slice, "a")
		fmt.Println(slice)
	}(slice)
	fmt.Println(slice)

	fmt.Println("TEST CASE 5")
	slice = make([]string, 2, 3)
	func(slice []string) {
		slice = append(slice, "a")
		slice[0] = "b"
		slice[1] = "b"
		fmt.Println(slice)
	}(slice)
	fmt.Println(slice)

	fmt.Println("TEST CASE 6")
	slice = make([]string, 2, 3)
	func(slice []string) {
		slice = append(slice, "a")
		slice[0] = "b"
		slice[1] = "b"
		fmt.Println(slice)
	}(slice)
	fmt.Println(slice)

	fmt.Println("TEST CASE 7")
	slice = make([]string, 2, 3)
	func(slice []string) {
		slice = append(slice, "a", "b")
		slice[0] = "b"
		slice[1] = "b"
		fmt.Println(slice)
	}(slice)
	fmt.Println(slice)

	fmt.Println("TEST CASE 8")
	slice = make([]string, 1, 3)
	func(slice []string) {
		slice = slice[1:3]
		slice[0] = "b"
		slice[1] = "b"
		fmt.Println(len(slice))
		fmt.Println(slice)
	}(slice)
	fmt.Println(len(slice))
	fmt.Println(slice)
}

func reserve(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func appendInt(arr []int, x int) []int {
	arrLen := len(arr) + 1
	var z []int
	if arrLen < cap(arr) {
		z = arr[:arrLen]
	} else {
		zcap := arrLen
		if zcap < 2*len(arr) {
			zcap = 2 * len(arr)
		}
		z = make([]int, arrLen, zcap)
		copy(z, arr)
	}

	z[len(arr)] = x
	return z
}
