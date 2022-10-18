package strings

import (
	"fmt"
	"strings"

	"github.com/google/uuid"
)

func TestStringSplit() {
	uniqid := uuid.New()
	uuidString := uniqid.String()
	fmt.Println(uuidString)
	splits := strings.Split(uuidString, "-")
	fmt.Println(splits[len(splits)-1])
}
