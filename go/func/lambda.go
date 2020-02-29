package main

import (
	"flag"
	"fmt"
)

// 遍历切片的每个元素, 通过给定函数进行元素访问
func visit(list []int, f func(int)) {
	for _, v := range list {
		f(v)
	}
}

var skillParam = flag.String("skill", "fire", "skill to perform")


func main() {
	func(data int) {
		fmt.Println("hello", data)
	}(100)

	// 将匿名函数体保存到f()中
	f := func(data int) {
		fmt.Println("hello", data)
	}
	// 使用f()调用
	f(100)


	// 使用匿名函数打印切片内容
	visit([]int{1, 2, 3, 4}, func(v int) {
		fmt.Println(v)
	})

	flag.Parse()
	var skill = map[string]func(){
		"fire": func() {
			fmt.Println("chicken fire")
		},
		"run": func() {
			fmt.Println("soldier run")
		},
		"fly": func() {
			fmt.Println("angel fly")
		},
	}


	if f, ok := skill[*skillParam]; ok {
		f()
	} else {
		fmt.Println("skill not found")
	}
}
