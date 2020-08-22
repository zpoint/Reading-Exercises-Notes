package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	var size int = len(s)
	var longest int = 1
	var beginIndex int = 0
	var endIndex int = 1
	var myMap map[uint8]int = make(map[uint8]int)
	if size == 0 {
		return 0
	}
	myMap[s[0]] = 0
	for endIndex < size {
		index, ok := myMap[s[endIndex]]

		if ok {
			newBeginIndex := index + 1
			for index := beginIndex; index < newBeginIndex; index++ {
				delete(myMap, s[index])
			}
			beginIndex = newBeginIndex
			myMap[s[endIndex]] = endIndex

		} else {
			currLongest := endIndex - beginIndex + 1
			if currLongest > longest {
				longest = currLongest
			}
			myMap[s[endIndex]] = endIndex
		}
		endIndex++
	}
	return longest
}

func main() {
	fmt.Println(lengthOfLongestSubstring("bbbbb"))
}
