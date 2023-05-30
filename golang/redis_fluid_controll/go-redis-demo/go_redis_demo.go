package go_redis_demo

import (
	"fmt"
	"github.com/go-redis/redis"
	"github.com/google/uuid"
	"strconv"
	"time"
)

const QueueKey = "queue"

func TestDemo() {
	client := redis.NewClient(&redis.Options{
		Addr: "localhost:6379",
	})

	fmt.Printf("Adding element to queue with score %v\n", time.Now().Unix())
	client.ZAdd(QueueKey, redis.Z{Score: float64(time.Now().Unix()), Member: uuid.New().String()}).Result()

	start := strconv.FormatInt(time.Unix(0, 0).Unix(), 10)
	stop := strconv.FormatInt(time.Now().Unix(), 10)

	elements, err := client.ZRangeByScore(QueueKey, redis.ZRangeBy{
		Min: start,
		Max: stop,
	}).Result()
	if err != nil {
		panic(err)
	}

	threeMinutesAgo := time.Now().Add(-3 * time.Minute).Unix()
	strThreeMinutesAgo := strconv.FormatInt(threeMinutesAgo, 10)
	count, err := client.ZCount(QueueKey, strThreeMinutesAgo, stop).Result()
	if err != nil {
		panic(err)
	}
	fmt.Printf("Count of elements with score between %v and %v: %v\n", strThreeMinutesAgo, stop, count)

	fmt.Printf("Elements with score between %v and %v:\n", start, stop)
	for _, element := range elements {
		fmt.Println(element)
	}

	fmt.Printf("Deleting elements with score between %v and %v minutes ago", start, strThreeMinutesAgo)
	deletedCount, err := client.ZRemRangeByScore(QueueKey, start, strThreeMinutesAgo).Result()
	if err != nil {
		panic(err)
	}
	fmt.Printf("Deleted %v elements\n", deletedCount)
}
