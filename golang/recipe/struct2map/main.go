package main

import (
	"fmt"
	"reflect"
)

type TestStruct struct {
	RetCode   int    `json:"ret_code"`
	RetMsg    string `json:"ret_msg"`
	SessionId string `json:"session_id"`
	Response  struct {
		TotalCount int `json:"total_count"`
		UserList   []struct {
			Id           int    `json:"id"`
			CreatedAt    string `json:"created_at"`
			UpdatedAt    string `json:"updated_at"`
			DeletedAt    string `json:"deleted_at"`
			UserName     string `json:"user_name"`
			Organization string `json:"organization"`
			UserType     int    `json:"user_type"`
		} `json:"user_list"`
	} `json:"response"`
}

func StructToMap(in interface{}, tagName string) (map[string]interface{}, error) {
	out := make(map[string]interface{})

	v := reflect.ValueOf(in)
	if v.Kind() == reflect.Ptr {
		v = v.Elem()
	}

	if v.Kind() != reflect.Struct { // 非结构体返回错误提示
		return nil, fmt.Errorf("ToMap only accepts struct or struct pointer; got %T", v)
	}

	t := v.Type()
	// 遍历结构体字段
	// 指定tagName值为map中key;字段值为map中value
	for i := 0; i < v.NumField(); i++ {
		fi := t.Field(i)
		if tagValue := fi.Tag.Get(tagName); tagValue != "" {
			out[tagValue] = v.Field(i).Interface()
		}
	}
	return out, nil
}

func main() {
	testS := TestStruct{}
	testS.SessionId = "23123"
	outmap, err := StructToMap(testS, "session_id")
	if err != nil {
		fmt.Println("error is ", err)
		return
	}
	fmt.Println(outmap)
}
