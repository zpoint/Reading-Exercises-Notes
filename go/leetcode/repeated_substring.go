package main

import "fmt"

func repeatedSubstringPattern(s string) bool {
	stringLen := len(s)
	if stringLen == 1 {
		return true
	}
	currentLen := stringLen / 2
	BigFor:
	for currentLen > 0 {
		if stringLen % currentLen != 0 {
			currentLen -= 1
			continue
		}
		firstStr := s[0:currentLen]
		for index := currentLen; index < stringLen; index += currentLen {
			t := s[index:index + currentLen]
			if t != firstStr {
				currentLen -= 1
				continue BigFor
			}
		}
		return true
	}
	return false
}

func main() {
	fmt.Println(repeatedSubstringPattern("abcabcabcabc"))
	fmt.Println(repeatedSubstringPattern("aba"))
}
