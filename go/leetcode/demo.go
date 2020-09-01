package main

import (
	"fmt"
	"reflect"
)

func main() {
	var bitMap []uint64 = []uint64{1<<62, 2, 3}
	for _, eachVal := range bitMap {
		fmt.Println(eachVal, reflect.TypeOf(eachVal))
	}
}
