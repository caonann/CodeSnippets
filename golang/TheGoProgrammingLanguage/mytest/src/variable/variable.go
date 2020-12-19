package variable

import (
	"fmt"
	"math"
)

func init() {
	fmt.Println("init variable")
}

//TestVariable ...
func TestVariable() {
	fmt.Println("TestVariable")
	x := 1
	y := 2
	x, y = y, x
	fmt.Printf("x %v,y %v\n", x, y)

}

//TestInt ...
func TestInt() {
	var num1 uint8 = 3 << 0
	var num2 uint8 = 3 << 1
	fmt.Printf("%08b\n%08b \n", num1, num2)
	fmt.Printf("num1|num2 %08b \n", num1|num2)
	fmt.Printf("num1&num2 %08b \n", num1&num2)
	fmt.Printf("num1^num2 %08b \n", num1^num2)
	fmt.Printf("num1&^num2 %08b \n", num1&^num2)

	var num uint8 = 0
	for i := uint(0); i < 8; i++ {
		num |= 1
		fmt.Printf("%08b\n", num)
		num <<= 1
	}

	const pi int = 3
	type MyInt int
	pia := MyInt(2)
	fmt.Printf("%T %[1]v\n", pi)
	fmt.Printf("%T %[1]v\n", pia)
	fmt.Println(math.Pi)
}
