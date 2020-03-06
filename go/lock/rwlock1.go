package main

import (
	"fmt"
	"sync"
)

var (
	// 逻辑中使用的某个变量
	count2 int

	// 与变量对应的使用互斥锁
	countGuard2 sync.RWMutex
)

func GetCount2() int {
	// 锁定
	countGuard2.RLock()
	// 在函数退出时解除锁定
	defer countGuard2.RUnlock()
	return count2
}

func SetCount2(c int) {
	countGuard2.Lock()
	count2 = c
	countGuard2.Unlock()
}

func main() {

	// 可以进行并发安全的设置
	SetCount2(1)

	// 可以进行并发安全的获取
	fmt.Println(GetCount2())
}
