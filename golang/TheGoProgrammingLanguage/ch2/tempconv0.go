package main

import "fmt"

type Celsius float64    //摄氏度
type Fahrenheit float64 //华氏度
const (
	AbsoluteZeroC Celsius = -273.15 //绝对0度
	FreezingC     Celsius = 0       //结冰点温度
	BoilingC      Celsius = 100     //沸水温度
)

func C2F(c Celsius) Fahrenheit {
	return Fahrenheit(c*9/5 + 32)
}

func F2C(f Fahrenheit) Celsius {
	return Celsius((f - 32) * 5 / 9)
}
func main() {
	fmt.Println(BoilingC - FreezingC)
	fmt.Println(C2F(BoilingC) - C2F(FreezingC))
}
