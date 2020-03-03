package main

import (
	"fmt"
	"sync"
	"time"
)

func lockFunc() {
	var a = 0
	var lock sync.Mutex
	for i := 0; i < 1000; i++ {
		go func(idx int) {
			lock.Lock()
			defer lock.Unlock()
			a += 1
			fmt.Printf("goroutine %d, a=%d\n", idx, a)
		}(i)
	}
	// 等待 1s 结束主程序
	// 确保所有协程执行完
	time.Sleep(time.Second)
}

func syncFunc() {
	var a = 0
	for i := 0; i < 10000; i++ {
		go func(idx int) {
			a += 1
			fmt.Println(a)
		}(i)
	}
	time.Sleep(time.Second)
}

func lockFunc2() {
	ch := make(chan struct{}, 2)
	var l sync.Mutex
	go func() {
		l.Lock()
		defer l.Unlock()
		fmt.Println("goroutine1: 我会锁定大概 2s")
		time.Sleep(time.Second * 2)
		fmt.Println("goroutine1: 我解锁了，你们去抢吧")
		ch <- struct{}{}
	}()
	go func() {
		fmt.Println("goroutine2: 等待解锁")
		l.Lock()
		fmt.Println("goroutine2: 获得锁")
		defer l.Unlock()
		fmt.Println("goroutine2: 欧耶，我也解锁了")
		ch <- struct{}{}
	}()
	// 等待 goroutine 执行结束
	for i := 0; i < 2; i++ {
		<-ch
	}
}

func main() {
	lockFunc2()
}
