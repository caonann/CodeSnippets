package redigo_demo

import (
	"fmt"
	"strconv"
	"strings"
	"time"

	"github.com/gomodule/redigo/redis"
	"github.com/google/uuid"
)

const QueueKey = "limit_checker_queue_redigo"

func RedigoDemo() {
	// Connect to Redis
	pool := &redis.Pool{
		MaxIdle:     5,
		IdleTimeout: 240 * time.Second,
		Dial: func() (redis.Conn, error) {
			return redis.Dial("tcp", "localhost:6379")
		},
	}

	conn := pool.Get()
	defer conn.Close()

	// Get all keys
	keys, err := redis.Strings(conn.Do("KEYS", "*"))
	if err != nil {
		panic(err)
	}

	sep := ","
	result := strings.Join(keys, sep)
	fmt.Printf("All keys: %v\n", result)
	_, err = conn.Do("ZADD", QueueKey, time.Now().Unix(), uuid.New().String())
	if err != nil {
		panic(err)
	}

	var cursor uint64
	for {
		res, err := redis.Values(conn.Do("SCAN", cursor, "MATCH", "limit_checker_*"))
		if err != nil {
			panic(err)
		}
		var matchedKeys []string
		_, err = redis.Scan(res, &cursor, &matchedKeys)
		if err != nil {
			panic(err)
		}
		fmt.Printf("Matched keys: %v\n", matchedKeys)
		if cursor == 0 {
			break
		}
	}

	start := strconv.FormatInt(time.Unix(0, 0).Unix(), 10)
	stop := strconv.FormatInt(time.Now().Unix(), 10)

	elements, err := redis.Strings(conn.Do("ZRANGEBYSCORE", QueueKey, start, stop))
	if err != nil {
		panic(err)
	}
	fmt.Printf("Elements with score between %v and %v:\n", start, stop)
	for _, element := range elements {
		fmt.Println(element)
	}

	threeMinutesAgo := time.Now().Add(-3 * time.Minute).Unix()
	strThreeMinutesAgo := strconv.FormatInt(threeMinutesAgo, 10)
	count, err := redis.Int(conn.Do("ZCOUNT", QueueKey, strThreeMinutesAgo, stop))
	if err != nil {
		panic(err)
	}
	fmt.Printf("Count of elements with score between %v and %v: %v\n", strThreeMinutesAgo, stop, count)

	fmt.Printf("Deleting elements with score between %v and %v minutes ago", start, strThreeMinutesAgo)
	deletedCount, err := redis.Int(conn.Do("ZREMRANGEBYSCORE", QueueKey, start, strThreeMinutesAgo))
	if err != nil {
		panic(err)
	}
	fmt.Printf("Deleted %v elements\n", deletedCount)
}
