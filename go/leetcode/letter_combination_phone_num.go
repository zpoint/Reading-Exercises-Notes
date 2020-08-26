package main

import "fmt"

var numMap = map[uint8]string{
	'2': "abc",
	'3': "def",
	'4': "ghi",
	'5': "jkl",
	'6': "mno",
	'7': "pqrs",
	'8': "tuv",
	'9': "wxyz",
}

func letterCombinations(digits string) []string {
	queue := make([]string, 0)
	if len(digits) == 0 {
		return queue
	}
	for _, eachChar := range numMap[digits[0]] {
		queue = append(queue, string(eachChar))
	}
	// fmt.Println(queue)

	for _, char := range digits[1:] {
		currLen := len(queue)
		for index := 0; index < currLen; index++ {
			currStr := queue[0]
			queue = queue[1:]
			for _, eachChar := range numMap[uint8(char)] {
				queue = append(queue, currStr+string(eachChar))
			}
		}
	}
	return queue
}

func main() {
	fmt.Println(letterCombinations("23"))
}
