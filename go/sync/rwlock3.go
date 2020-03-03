package main

import (
	"sync"
	"time"
)

var m3 *sync.RWMutex

func main() {
	m3 = new(sync.RWMutex)
	// 写的时候啥也不能干
	go write3(1)
	go read3(2)
	go write3(3)
	time.Sleep(8*time.Second)
}

func read3(i int) {
	println(i,"read start")
	m3.RLock()
	println(i,"reading")
	time.Sleep(1*time.Second)
	m3.RUnlock()
	println(i,"read over")
}

func write3(i int) {
	println(i, "write start")
	m3.Lock()
	println(i, "writing")
	time.Sleep(3*time.Second)
	m3.Unlock()
	println(i, "write over")
}
