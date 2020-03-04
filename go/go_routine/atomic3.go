package main

import (
	"fmt"
	"runtime"
	"sync"
)

var (
	counter4 int64
	wg4      sync.WaitGroup
	mutex   sync.Mutex
)

func main() {
	wg4.Add(2)

	go incCounter3(1)
	go incCounter3(2)

	wg4.Wait()
	fmt.Println(counter4)
}

func incCounter3(id int) {
	defer wg4.Done()

	for count := 0; count < 2; count++ {
		//同一时刻只允许一个goroutine进入这个临界区
		mutex.Lock()
		{
			value := counter4
			runtime.Gosched()
			value++
			counter4 = value
		}
		mutex.Unlock() //释放锁，允许其他正在等待的goroutine进入临界区
	}
}