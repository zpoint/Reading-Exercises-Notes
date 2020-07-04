package main

import "fmt"

func gen(nums ...int) <-chan int {
	out := make(chan int)
	go func() {
		for _, n := range nums {
			out <- n
		}
		close(out)
	}()
	return out
}

func main() {
	c := gen(1, 2, 3)
	for data := range c {
		fmt.Printf("value: %d\n", data)
	}
}
