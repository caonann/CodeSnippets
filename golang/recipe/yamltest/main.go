package main

import (
	"fmt"
	"gopkg.in/yaml.v3"
	"log"
	"reflect"
	"strconv"
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

func formatAtom(v reflect.Value) string {
	switch v.Kind() {
	case reflect.Invalid:
		return "invalid"
	case reflect.Int, reflect.Int8, reflect.Int16,
		reflect.Int32, reflect.Int64:
		return strconv.FormatInt(v.Int(), 10)
	case reflect.Uint, reflect.Uint8, reflect.Uint16,
		reflect.Uint32, reflect.Uint64, reflect.Uintptr:
		return strconv.FormatUint(v.Uint(), 10)
	// ...floating-point and complex cases omitted for brevity...
	case reflect.Bool:
		return strconv.FormatBool(v.Bool())
	case reflect.String:
		return strconv.Quote(v.String())
	case reflect.Chan, reflect.Func, reflect.Ptr, reflect.Slice, reflect.Map:
		return v.Type().String() + " 0x" +
			strconv.FormatUint(uint64(v.Pointer()), 16)
	default: // reflect.Array, reflect.Struct, reflect.Interface
		return v.Type().String() + " value"
	}
}

var totalPath [][]string

func walk(v reflect.Value, path []string) {
	//fmt.Printf("Visiting %v\n", v)
	// Indirect through pointers and interfaces
	for v.Kind() == reflect.Ptr || v.Kind() == reflect.Interface {
		v = v.Elem()
	}

	switch v.Kind() {
	case reflect.Array, reflect.Slice:
		for i := 0; i < v.Len(); i++ {
			curPath := make([]string, len(path))
			copy(curPath, path)
			curPath = append(curPath, string(i))
			walk(v.Index(i), curPath)
		}
	case reflect.Map:
		for _, k := range v.MapKeys() {
			curPath := make([]string, len(path))
			copy(curPath, path)
			curPath = append(curPath, formatAtom(k))
			walk(v.MapIndex(k), curPath)
		}
	default:
		totalPath = append(totalPath, path)
	}
}

func TestYaml() {
	yamlstruct := make(map[string]interface{})
	err := yaml.Unmarshal([]byte(data), yamlstruct)
	if err != nil {
		log.Fatal("error :%v", err)
	}

	vt := reflect.ValueOf(yamlstruct)
	walk(vt, []string{})
	for _, line := range totalPath {
		for _, item := range line {
			fmt.Printf("%+v", item)
		}
		fmt.Printf("\n")
	}
}
func main() {
	TestYaml()
}
