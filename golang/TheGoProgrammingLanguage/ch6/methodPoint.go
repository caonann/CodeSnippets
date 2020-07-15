package main

import "fmt"

type myclass struct {
	x int64
	y int64
}

type values map[string][]string

func (m *myclass) String() string {
	fmt.Printf("x+y=%d+%d\n", m.x, m.y)
	var tmpstring string
	fmt.Sprintf(tmpstring, "x+y=%d+%d\n", m.x, m.y)
	return tmpstring
}

func (m *myclass) SetValue(xvalue, yvalue int64) {
	m.x = xvalue
	m.y = yvalue
}

//非指针的接收器是值拷贝，所以是安全的
func (m myclass) SetValue2(xvalue, yvalue int64) {
	m.x = xvalue
	m.y = yvalue
}

func (v values) add(key, value string) {
	v[key] = append(v[key], value)
}

func (v values) getall() {
	for key, v := range v {
		fmt.Printf("%v:%v\n", key, v)
	}
}
func main() {
	oitem := myclass{x: 1, y: 2}
	oitem.String()
	oitem.SetValue(3, 5)
	oitem.String()
	oitem.SetValue2(5, 5)
	oitem.String()
	ovalue := values{"hulk": {"init"}}
	ovalue.add("cc", "mm")
	ovalue.getall()
	var tmpval values = ovalue
	tmpval.getall()
	ovalue.add("ccc", "mmm")
	tmpval.getall()

}
