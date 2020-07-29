package main

import (
	"fmt"
)

func main() {
	makeThumbnails([]string{"filea", "fileb", "filec"})
}

func makeThumbnails(filenames []string) {
	for _, f := range filenames {
		fmt.Printf("filename:%v\n", f)

	}
}
