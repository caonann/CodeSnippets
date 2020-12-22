package arrary

import (
	"bytes"
	"fmt"
)

func TestSlice() {
	weeks := []string{1: "mon", "tus", "wed", "thu", "fri", "sat", "sun"}
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
	fmt.Printf("%q", runes)

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
