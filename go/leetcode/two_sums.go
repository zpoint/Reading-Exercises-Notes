package main

import "fmt"

func twoSum(nums []int, target int) []int {
	var result []int = make([]int, 2)
	var numIndex map[int]int = make(map[int]int, len(nums))
	for i, v := range nums {
		numIndex[v] = i
	}

	for i, v := range nums {
		targetNum := target - v
		index, ok := numIndex[targetNum]

		// fmt.Println("i", i, v, index, ok)
		if ok && index != i {
			result[0] = i
			result[1] = index
			return result
		}
	}
	return result
}

func main() {
	a := [3]int{3, 2, 4}
	res := twoSum(a[:], 6)
	fmt.Println("res", res)
}
