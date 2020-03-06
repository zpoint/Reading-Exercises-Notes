package main

import (
	"context"
	"fmt"
	"time"
)

func main() {
	gen := func(ctx context.Context) <-chan int {
		dst := make(chan int)
		n := 1
		fmt.Printf("going to go\n")
		go func() {
			for {
				select {
				case <-ctx.Done():
					fmt.Printf("n: %d, ctx done\n", n)
					return // return结束该goroutine，防止泄露
				case dst <- n:
					fmt.Printf("n: %d, n++\n", n)
					n++
				}
			}
		}()
		return dst
	}
	ctx, cancel := context.WithCancel(context.Background())
	defer cancel() // 当我们取完需要的整数后调用cancel
	for n := range gen(ctx) {
		fmt.Println(n)
		if n == 5 {
			break
		}
	}
	time.Sleep(time.Second*1)
}
