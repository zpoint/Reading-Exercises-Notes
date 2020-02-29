package main

import "fmt"

func example() {
	var highRiseBuilding [30]int
	for i := 0; i < 30; i++ {
		highRiseBuilding[i] = i + 1
	}
	// 区间
	fmt.Println(highRiseBuilding[10:15])
	// 中间到尾部的所有元素
	fmt.Println(highRiseBuilding[20:])
	// 开头到中间指定位置的所有元素
	fmt.Println(highRiseBuilding[:2])
}

func main() {
	var a  = [3]int{1, 2, 3}
	fmt.Println(a, a[1:2])
	example()

	b := []int{1, 2, 3}
	fmt.Println(b[0:0])
	fmt.Println(len(b))

	x := make([]int, 2)
	y := make([]int, 2, 10)
	fmt.Println(x, y)
	fmt.Println(len(x), len(y))
}
