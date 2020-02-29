package main

import "fmt"

func go_to_test() {
	for x := 0; x < 10; x++ {
		for y := 0; y < 10; y++ {
			if y == 2 {
				// 跳转到标签
				goto breakHere
			}
		}
	}
	// 手动返回, 避免执行进入标签
	return
	// 标签
breakHere:
	fmt.Println("done")
}

func main() {
	go_to_test()
	var x int8 = 3

	for x = 1; x < 10; x += 1 {
		goto label1
	}

	label1:
		fmt.Printf("in label1, x: %d\n", x)
}
