package map_container

import (
	"fmt"
	"github.com/google/uuid"
	"strings"
)

type MyMap map[string]interface{}

type MyData struct {
	m MyMap
}

var GData *MyData

func (m *MyData) String() string {
	var resultBuilder strings.Builder
	resultBuilder.WriteString("{")
	comaNeeded := false
	for k, v := range m.m {
		if comaNeeded {
			resultBuilder.WriteString(", ")
		}
		comaNeeded = true
		resultBuilder.WriteString(fmt.Sprintf("%s: %v", k, v))
	}

	resultBuilder.WriteString("}")
	return resultBuilder.String()
}

func init() {
	GData = new(MyData)
	GData.m = MyMap{}
	for i := 0; i < 1000; i++ {
		key := uuid.New().String()
		GData.m[key] = "aabbcc"
	}
}
