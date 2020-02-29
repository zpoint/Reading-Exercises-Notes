package main

import (
	"fmt"
	"sync"
)


func bad() {
	// 创建一个int到int的映射
	m := make(map[int]int)
	// 开启一段并发代码
	go func() {
		// 不停地对map进行写入
		for {
			m[1] = 1
		}
	}()
	// 开启一段并发代码
	go func() {
		// 不停地对map进行读取
		for {
			_ = m[1]
		}
	}()
	// 无限循环, 让并发程序在后台执行
	for {
	}
}

func good() {
	var scene sync.Map
	// 将键值对保存到sync.Map
	scene.Store("greece", 97)
	scene.Store("london", 100)
	scene.Store("egypt", 200)
	// 从sync.Map中根据键取值
	fmt.Println(scene.Load("london"))
	// 根据键删除对应的键值对
	scene.Delete("london")
	// 遍历所有sync.Map中的键值对
	scene.Range(func(k, v interface{}) bool {
		fmt.Println("iterate:", k, v)
		return true
	})
}

func main() {
	// bad()
	good()
}
