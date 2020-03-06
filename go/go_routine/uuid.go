package main

import (
	"fmt"
	"sync"
	"sync/atomic"
)

var (
	// 序列号
	seq int64
	seq2 int64
	wgUUID sync.WaitGroup
)

// 序列号生成器
func GenID() int64 {
	// 尝试原子的增加序列号
	defer wgUUID.Done()
	atomic.AddInt64(&seq, 1)
	return seq
}

// 序列号生成器
func GenIDNoRace() int64 {
	// 尝试原子的增加序列号
	defer wgUUID.Done()
	return atomic.AddInt64(&seq2, 1)
}

func main() {
	wgUUID.Add(20000)
	//生成10个并发序列号
	for i := 0; i < 10000; i++ {
		go GenID()
	}


	for i := 0; i < 10000; i++ {
		go GenIDNoRace()
	}
	wgUUID.Wait()
	fmt.Println(seq)
	fmt.Println(seq2)


}
