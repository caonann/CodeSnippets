//测试主线程等待子线程的场景
package main

import (
	"fmt"
	"time"
)

func mainThread(done chan struct{}) {
	fmt.Println("main thread staring...")
	time.Sleep(time.Second * 5)
	done <- struct{}{}
}
