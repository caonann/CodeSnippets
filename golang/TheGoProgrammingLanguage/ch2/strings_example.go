package main

import "fmt"

func main() {
	teststr := "hello hulkcao"
	fmt.Println(teststr[:5])
	fmt.Println(teststr[6:])
	fmt.Println(teststr[:])
	//原生字符串，类似于python中的r
	const GoUsage = `this is a tes '
dear all
please check the email address
	`
	fmt.Println(GoUsage)

}
