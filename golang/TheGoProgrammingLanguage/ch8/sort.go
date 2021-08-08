package main

import (
	"fmt"
	"sort"
)

// Main function
func main() {

	// Creating and searching an element
	// in the given slice of strings
	// Using SearchStrings function
	res1 := sort.SearchStrings([]string{"apple", "banana",
		"kiwi", "orange"}, "kiwi")

	res2 := sort.SearchStrings([]string{"Cat", "Cow",
		"Dog", "Parrot"}, "Cau")

	// Displaying the results
	fmt.Println("Result 1: ", res1)
	fmt.Println("Result 2: ", res2)

}
