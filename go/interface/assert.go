package main

import "fmt"

func normal() {
	var x interface{}
	x = 10
	value, ok := x.(int)
	fmt.Print(value, ",", ok)
}

func panic() {
	var x interface{}
	x = "Hello"
	value := x.(int)
	fmt.Println(value)
}


func getType(a interface{}) {
	switch a.(type) {
	case int:
		fmt.Println("the type of a is int")
	case string:
		fmt.Println("the type of a is string")
	case float64:
		fmt.Println("the type of a is float")
	default:
		fmt.Println("unknown type")
	}
}


func main() {
	getType(3.33)
	normal()
	panic()
}
