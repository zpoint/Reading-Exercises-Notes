package main

import "fmt"

/*
var 通道实例 chan<- 元素类型    // 只能发送通道
var 通道实例 <-chan 元素类型    // 只能接收通道
 */

func main() {
	ch := make(chan int)
	// 声明一个只能发送的通道类型, 并赋值为ch
	var chSendOnly chan<- int = ch
	//声明一个只能接收的通道类型, 并赋值为ch
	var chRecvOnly <-chan int = ch
	fmt.Println("chSendOnly", chSendOnly, "chRecvOnly", chRecvOnly)
}
