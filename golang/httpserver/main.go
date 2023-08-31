package main

import (
	"fmt"
	"net/http"
	"strconv"
	"time"

	"github.com/google/uuid"
)

// 定义一个处理器函数
func benchmarkHandler(w http.ResponseWriter, r *http.Request) {
	// 在这里你可以添加你的业务逻辑
	uid := uuid.NewString()
	//fmt.Fprintf(w, "Benchmark path hit! %v", uid)
	queryParams := r.URL.Query()
	enableSleepStr := queryParams.Get("enable_sleep")

	enableSleep, err := strconv.Atoi(enableSleepStr)
	if err != nil {
		// 处理转换错误
		fmt.Println("Error converting enable_sleep to int:", err)
	} else {
		if enableSleep != 0 {
			time.Sleep(100 * time.Millisecond)
		}
	}

	fmt.Fprintf(w, "Benchmark path hit done! %v", uid)
}

func main() {
	// 使用http库的HandleFunc函数来关联处理器函数
	http.HandleFunc("/benchmark", benchmarkHandler)
	// 使用http库的ListenAndServe函数来启动服务器
	fmt.Println("Starting server on port 8000")
	if err := http.ListenAndServe(":8000", nil); err != nil {
		fmt.Println("Failed to start server:", err)
	}
}
