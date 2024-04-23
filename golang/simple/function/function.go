package function

var IterationTimes int64 = 0

func Fibonacci(n int) int {
	if n <= 1 {
		return 1
	} else if n == 2 {
		return 2
	}
	IterationTimes++
	return Fibonacci(n-1) + Fibonacci(n-2)
}


func AssianValue()*int {
	var a int
	return &a
}