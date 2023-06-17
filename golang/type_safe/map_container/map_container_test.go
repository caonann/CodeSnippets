package map_container

import (
	"fmt"
	"github.com/google/uuid"
	"runtime/debug"
	"testing"
)

func BenchmarkMapData(b *testing.B) {
	defer func() {
		if r := recover(); r != nil {
			// 打印错误原因
			fmt.Println("Recovered from panic:", r)
			// 打印详细的调用栈
			debug.PrintStack()
		}
	}()
	// 初始化测试变量
	key := uuid.New().String()
	value := "example_value"
	//m := sync.Mutex{}
	// 重置定时器，以排除测试准备工作所需的时间
	b.ResetTimer()
	c := make(chan int)
	fmt.Println("map size is ", len(GData.m))
	go func() {
		//m.Lock()
		//defer m.Unlock()

		for k, v := range GData.m {
			_ = k
			_ = v
		}

		c <- 1
	}()
	// 使用 b.N 执行迭代操作
	//m.Lock()
	for i := 0; i < b.N; i++ {
		// 这是我们要测试的操作：
		// 向 MapData 添加数据

		GData.m[key] = value

		// 从 MapData 中获取数据
		_ = GData.m[key]

	}
	//m.Unlock()
	<-c
}
