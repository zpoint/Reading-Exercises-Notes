package main

import "fmt"

func main() {
	var any interface{}
	any = 1
	fmt.Println(any)
	any = "hello"
	fmt.Println(any)
	any = false
	fmt.Println(any)

	// 声明a变量, 类型int, 初始值为1
	var a int = 1
	// 声明i变量, 类型为interface{}, 初始值为a, 此时i的值变为1
	var i interface{} = a
	// 声明b变量, 尝试赋值i
	var b int = i.(int)
	fmt.Println(b)

	// a保存整型
	var x interface{} = 100
	// b保存字符串
	var y interface{} = "hi"
	// 两个空接口不相等
	fmt.Println(x == y)

	// c保存包含10的整型切片
	var c interface{} = []int{10}
	// d保存包含20的整型切片
	var d interface{} = []int{20}
	// 这里会发生崩溃
	fmt.Println(c == d)
}
