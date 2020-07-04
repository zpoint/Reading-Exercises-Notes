package main

import "fmt"

func main() {
	ch1 := make(chan int, 1)
	ch2 := make(chan int, 1)
	ch1 <- 1
	ch2 <- 2
	close(ch1)
	var i int = 0
	var ok bool = true
	for {
		select {
		case i, ok = <-ch1:
			fmt.Println("ch1", i, ok)
		case i, ok = <-ch2:
			fmt.Println("ch2", i, ok)
		}
		if !ok {
			break
		}
	}
}
