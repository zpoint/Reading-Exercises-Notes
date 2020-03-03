package main

import (
	"sync"
	"time"
)

var m *sync.RWMutex

func main() {
	m = new(sync.RWMutex)
	// 多个同时读
	go read2(1)
	go read2(2)
	time.Sleep(2*time.Second)
}

func read2(i int) {
	println(i,"read start")
	m.RLock()
	println(i,"reading")
	time.Sleep(1*time.Second)
	m.RUnlock()
	println(i,"read over")
}
