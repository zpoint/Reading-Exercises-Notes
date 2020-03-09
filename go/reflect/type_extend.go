package main

import (
	"fmt"
	"reflect"
)

func main() {
	var x uint8 = 'x'
	v := reflect.ValueOf(x)
	fmt.Println("type:", v.Type())                            // uint8.
	fmt.Println("kind is uint8: ", v.Kind() == reflect.Uint8) // true.
	x = uint8(v.Uint())

	type MyInt int
	var xx MyInt = 7
	vv := reflect.ValueOf(xx)// v.Uint returns a uint64.
	fmt.Println("type: ", vv.Type(), "kind: ", vv.Kind(), "vv.interface", vv.Interface())
}
