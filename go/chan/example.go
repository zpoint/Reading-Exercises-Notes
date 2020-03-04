package main

import (
	"fmt"
	"time"
)

func BlockingAccept(myChan chan interface{}) {
	var count int = 1
	for {
		fmt.Printf("count: %d\n", count)
		var myVar interface{} = <-myChan
		fmt.Println(myVar)
		count++
	}
}

func NonBlockingAccept(myChan chan interface{}) {
	var count int = 1
	for {
		fmt.Printf("count: %d\n", count)
		myVar, ok := <-myChan
		fmt.Println(myVar, ok)
		count++
	}
}

func example() {
	ch1 := make(chan int)                 // 创建一个整型类型的通道
	ch2 := make(chan interface{})         // 创建一个空接口类型的通道, 可以存放任意格式
	type Equip struct{ /* 一些字段 */ }
	ch3 := make(chan *Equip)             // 创建Equip指针类型的通道, 可以存放*Equip
	fmt.Printf("%v, %v, %v\n", ch1, ch2, ch3)

	// 创建一个空接口通道
	ch := make(chan interface{})
	go NonBlockingAccept(ch)
	// 将0放入通道中
	ch <- 0
	// 将hello字符串放入通道中
	ch <- "hello"

	time.Sleep(time.Second * 30)
}

func main() {
	example()
}
