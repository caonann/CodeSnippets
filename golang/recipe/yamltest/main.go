package main

import (
	"fmt"
	yaml "gopkg.in/yaml.v3"
	"log"
	"reflect"
)

var data = `
speech_rep_info:
  anim_rep:
    alg_info:
      err_msg: OK
      err_no: 0
      first_delay: 0.06700000166893005
      rtf: 0.008999999612569809
    err_msg: success
    err_no: 0
    session_id: 2022_08_14_14_21_39
  begin: true
  end: true
  speech_rsp:
    err_msg: OK
    err_no: 0
    final: true
    fps: 60
    sessionid: 2022_08_14_14_21_39
    th_dim: 16
    th_feat: []
`

func walk(v reflect.Value, path []string) {
	fmt.Printf("Visiting %v\n", v)
	// Indirect through pointers and interfaces
	for v.Kind() == reflect.Ptr || v.Kind() == reflect.Interface {
		v = v.Elem()
	}
	switch v.Kind() {
	case reflect.Array, reflect.Slice:
		for i := 0; i < v.Len(); i++ {

			walk(v.Index(i), path)
		}
	case reflect.Map:
		for _, k := range v.MapKeys() {
			//path = append(path, k)
			walk(v.MapIndex(k), path)
		}
	default:
		// handle other types
	}
}

func TestYaml() {
	yamlstruct := make(map[string]any)
	err := yaml.Unmarshal([]byte(data), yamlstruct)
	if err != nil {
		log.Fatal("error :%v", err)
	}

	vt := reflect.ValueOf(yamlstruct)
	walk(vt)
}
func main() {
	TestYaml()
}
