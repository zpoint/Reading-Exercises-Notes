package main

import (
	"bytes"
	"fmt"
	"log"
	"runtime"
	"sync"
	"sync/atomic"
	"time"
)

func main() {
	runtime.GOMAXPROCS(3)
	cv := sync.NewCond(&sync.Mutex{})
	go func() {
		for range time.Tick(2 * time.Second) { // 通过tick控制两个人的步调
			cv.Broadcast()
		}
	}()
	takeStep := func(name, dirname string, dir *int32) {
		log.Println(name, dirname, "trying to get lock", *dir)
		cv.L.Lock()
		log.Println(name, dirname, "Locked, waiting", *dir)
		cv.Wait()
		log.Println(name, dirname, "Wait return, going to unlock", *dir)
		cv.L.Unlock()
	}
	tryDir := func(name, dirName string, dir *int32, out *bytes.Buffer) bool {
		fmt.Fprintf(out, " %+v", dirName)
		atomic.AddInt32(dir, 1)
		takeStep(name, dirName, dir)                      //走上一步
		if atomic.LoadInt32(dir) == 1 { //走成功就返回
			fmt.Fprint(out, ". Success!")
			return true
		}
		takeStep(name, dirName, dir) // 没走成功，再走回来
		atomic.AddInt32(dir, -1)
		return false
	}
	var left, right int32
	tryLeft := func(name string, out *bytes.Buffer) bool {
		return tryDir(name, "向左走", &left, out)
	}
	tryRight := func(name string, out *bytes.Buffer) bool {
		return tryDir(name, "向右走", &right, out)
	}
	walk := func(walking *sync.WaitGroup, name string) {
		var out bytes.Buffer
		defer walking.Done()
		defer func() { fmt.Println(out.String()) }()
		fmt.Fprintf(&out, "%v is trying to scoot:", name)
		for i := 0; i < 5; i++ {
			fmt.Println(name, "i: ", i)
			if tryLeft(name, &out) || tryRight(name, &out) {
				return
			}
		}
		fmt.Fprintf(&out, "\n%v is tried!", name)
	}
	var trail sync.WaitGroup
	trail.Add(2)
	go walk(&trail, "男人") // 男人在路上走
	go walk(&trail, "女人") // 女人在路上走
	trail.Wait()
}