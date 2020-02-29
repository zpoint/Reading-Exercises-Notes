package main

import "fmt"

func main() {
	var x interface{} =func(x int)string{
		return fmt.Sprintf("d:%d",x)
	}
	x = nil

	switch v:=x.(type) {            // 局部变量v是类型转换后的结果
	case nil:
		println("nil")
	case*int:
		println(*v)
	case func(int)string:
		println(v(100))
	case fmt.Stringer:
		fmt.Println(v)
	default:
		println("unknown")
	}
}