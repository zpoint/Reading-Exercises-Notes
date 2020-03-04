package main
import (
	"fmt"
	"runtime"
	"sync"
	"sync/atomic"
)

var (
	counter2 int64
	wg2      sync.WaitGroup
)
func main() {
	wg2.Add(2)
	go incCounter(1)
	go incCounter(2)
	wg2.Wait() //等待goroutine结束
	fmt.Println(counter2)

	fmt.Println("runtime.NumCPU(): ", runtime.NumCPU())
}

func incCounter(id int) {
	defer wg2.Done()
	for count := 0; count < 2000; count++ {
		atomic.AddInt64(&counter2, 1) //安全的对counter加1
		runtime.Gosched()
	}
}