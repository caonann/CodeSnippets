package main

import (
	"time"

	"fmt"

	"github.com/go-redis/redis"
)

func main() {
	// Connect to Redis
	client := redis.NewClient(&redis.Options{
		Addr: "localhost:6379",
	})

	// Set the maximum size of the priority queue
	maxSize := 10

	// Add elements to the priority queue with a score representing the priority and a value representing the element
	client.ZAdd("queue", &redis.Z{Score: 1, Member: "element1"}, &redis.Z{Score: 2, Member: "element2"})

	// Set an expiration time for each element in the priority queue
	client.ZAdd("queue", &redis.Z{Score: 3, Member: "element3"}).Result()
	client.Expire("queue", time.Second*10)

	// Remove elements from the priority queue when the size exceeds the maximum size
	client.ZRemRangeByRank("queue", 0, -maxSize-1)

	// Get the elements from the priority queue in order of priority
	elements, err := client.ZRange("queue", 0, -1).Result()
	if err != nil {
		panic(err)
	}

	// Print the elements in order of priority
	fmt.Println("Elements in priority order:")
	for _, element := range elements {
		fmt.Println(element)
	}
}
