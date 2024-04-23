package function

import "testing"

func TestFunction(t *testing.T) {
	p := AssianValue()
	*p = 1
	*AssianValue() = 2
}
