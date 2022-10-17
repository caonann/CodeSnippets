package main

import (
	"fmt"
	"os"
	"time"
)

//GetAudioSizeFromDuration 给定音频时长,返回音频大小
func GetAudioSizeFromDuration(duration time.Duration, sampling int, bitWide int) int {
	seconds := float64(duration) / float64(time.Second)
	return int((seconds * float64(sampling) * float64(bitWide)) / 8)
}

//GetAudioDuration 返回音频时长(s)
func GetAudioDuration(audioSize int, bitWide int) time.Duration {
	//音频时间=音频大小（字节）/(采样率*位数/8)
	seconds := float64(audioSize) / float64((24000*bitWide)/8)
	return time.Duration(seconds * float64(time.Second))
}

type Content struct {
	content []byte
}

func main() {
	duration := GetAudioDuration(8000, 16)
	fmt.Println("duration is ", duration)
	audioSize := GetAudioSizeFromDuration(time.Second, 16000, 16)
	fmt.Println("audio size is ", audioSize)

	fileContent, err := os.ReadFile("number_convert")
	if err != nil {
		panic(err)
	}
	fmt.Println("len1 is ", len(fileContent))
	c := Content{}
	c.content = fileContent[:len(fileContent)/2]
	fmt.Println("after len is ", len(c.content))
}
