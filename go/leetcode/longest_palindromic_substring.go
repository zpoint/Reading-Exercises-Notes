package main

import "fmt"

func longestPalindrome(s string) string {
	stringLen := len(s)
	longest := 0
	var longestBegin = 0
	var longestEnd = 0
	if len(s) == 0 {
		return ""
	}
	var matrix [][]bool = make([][]bool, stringLen)
	for index := 0; index < stringLen; index++ {
		matrix[index] = make([]bool, stringLen)
		matrix[index][index] = true
	}
	for length := 2; length <= stringLen; length++ {
		for beginIndex := 0; beginIndex <= stringLen - length; beginIndex++ {
			endIndex := beginIndex + length - 1
			if s[beginIndex] != s[endIndex] {
				matrix[beginIndex][endIndex] = false
				continue
			} else if length > 2 && !matrix[beginIndex+1][endIndex-1] {
				matrix[beginIndex][endIndex] = false
				continue
			}
			matrix[beginIndex][endIndex] = true
			if length > longest {
				longest = length
				longestBegin = beginIndex
				longestEnd = endIndex
			}
		}
	}
	return s[longestBegin:longestEnd+1]
}

func main() {
	fmt.Println(longestPalindrome("cbbd"))
}
