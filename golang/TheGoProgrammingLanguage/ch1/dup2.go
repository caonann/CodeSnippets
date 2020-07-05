package main

import (
	"bufio"
	"fmt"
	"os"
)

func countLines(f *os.File, counts map[string]int, filename string, filesname map[string]string) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		counts[input.Text()]++
		filesname[input.Text()] = filename
	}
	// NOTE: ignoring potential errors from input.Err()
}

func main() {
	filesname := make(map[string]string)
	counts := make(map[string]int)
	files := os.Args[1:]
	if len(files) == 0 {
		countLines(os.Stdin, counts, "nonefile", filesname)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintln(os.Stderr, "dup2: %v\n", err)
				continue
			}
			countLines(f, counts, arg, filesname)
			f.Close()
		}
	}

	for line, n := range counts {
		if n > 1 {
			fmt.Printf("%d\t%s\tfilename: %s\n", n, line, filesname[line])
		}
	}

}
