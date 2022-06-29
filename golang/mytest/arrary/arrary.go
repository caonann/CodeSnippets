package arrary

import (
	"crypto/sha256"
	"fmt"
)

var globalArr [10]int

func init() {
	fmt.Println("#####init arrary############")
	for i := 0; i < len(globalArr); i++ {
		globalArr[i] = i
	}
}

func TestArr() {
	for _, v := range globalArr {
		fmt.Println(v)
	}
	testArr1 := [3]string{"a", "b", "c"}
	testArr2 := [...]int32{1, 2, 3, 4}
	fmt.Println(testArr1, len(testArr2))
	fmt.Printf("%T\n", testArr2)

	const (
		usd = iota
		gbp
		rmb
	)

	var testArr3 = []string{usd: "$", gbp: "yingbang", rmb: "￥"}
	testArr4 := [...]int{3: -1}
	testArr5 := [...]int{0, 0, 0, -1}
	fmt.Println(testArr3, testArr4, testArr4 == testArr5)

	c1 := sha256.Sum256([]byte("hulk"))
	c2 := sha256.Sum256([]byte("Hulk"))
	fmt.Printf("%T,%[1]x,%x\n", c1, c2)
	diffByte(&c1, &c2)
}

func diffByte(c1 *[32]uint8, c2 *[32]uint8) {
	var sum int = 0
	for i := 0; i < 32; i++ {
		c := (*c1)[i] ^ (*c2)[i]
		fmt.Printf("%b", c)
		for ; c > 0; c = c & (c - 1) {
			sum++
		}
	}
	fmt.Printf("total sum is %v", sum)
}
