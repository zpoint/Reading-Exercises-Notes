package main

import "fmt"

func countSubstrings(s string) int {
	stringLen := len(s)
	var count int = 0
	var matrix [][]bool = make([][]bool, stringLen)
	for index := 0; index < stringLen; index++ {
		matrix[index] = make([]bool, stringLen)
		matrix[index][index] = true
		count++
	}
	for size := 2; size <= stringLen; size++ {
		// fmt.Println("size", size, count)
		for beginIndex := 0; beginIndex < stringLen - size + 1; beginIndex++ {
			endIndex := beginIndex + size - 1
			// fmt.Println("beginIndex", beginIndex, "endIndex", endIndex, "stringLen - size", stringLen - size)
			if s[beginIndex] != s[endIndex] {
				matrix[beginIndex][endIndex] = false
			} else if beginIndex < endIndex - 1 {
				matrix[beginIndex][endIndex] = matrix[beginIndex+1][endIndex-1]
				if matrix[beginIndex][endIndex] {
					count++
				}
			} else {
				matrix[beginIndex][endIndex] = true
				count++
			}
			// fmt.Println("22beginIndex", beginIndex, "endIndex", endIndex)
		}
	}
	return count
}

func main() {
	fmt.Println((1 + 2) / 2)
	fmt.Println(countSubstrings("aaaaa"))
}