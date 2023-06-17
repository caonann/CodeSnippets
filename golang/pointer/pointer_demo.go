package main

import (
	"context"
	"fmt"
	"net/http"
	"strings"
)

type Test struct {
	number int
	name   string
}

var streamKey = "stream"

func Input(r *http.Request) string {
	useStream := true
	ctx := context.WithValue(r.Context(), streamKey, useStream)
	r = r.WithContext(ctx)
	return "hello"
}
func main() {
	reqBody := `{"model":"gpt-3.5-turbo","messages":[{"role":"user","content":"唐诗三百首"}],"stream":true}`
	req, err := http.NewRequest("POST", "/api/v1/openai", strings.NewReader(reqBody))
	if err != nil {
		fmt.Println(err)
	}
	Input(req)
	fmt.Println(req.Context().Value(streamKey))
}
