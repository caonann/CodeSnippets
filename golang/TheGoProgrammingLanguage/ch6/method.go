package main

import "fmt"

type tmpstruct struct {
	name string
	x    int64
}

func distance(x, y float64) float64 {
	return y - x
}

func (t tmpstruct) distance(y float64) float64 {
	return y - float64(t.x)
}

func main() {
	distance := distance(10, 7)
	fmt.Println(distance)
	tmpdistance := tmpstruct{x: 2, name: "hulk"}
	ret := tmpdistance.distance(20)
	fmt.Println(ret)
}
