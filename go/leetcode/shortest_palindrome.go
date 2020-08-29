package main

import "fmt"

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func shortestPalindrome(s string) string {
	strLen := len(s)
	OuterLoop:
	for prefixLen := 0; prefixLen < strLen; prefixLen++ {
		needExamBeginIndex := 0
		needExamEndIndex := strLen - prefixLen - 1
		// fmt.Println(needExamBeginIndex, needExamEndIndex, string(s[needExamBeginIndex]), string(s[needExamEndIndex]))
		for needExamBeginIndex <= needExamEndIndex {
			// fmt.Println("zz", needExamBeginIndex, needExamEndIndex, string(s[needExamBeginIndex]), string(s[needExamEndIndex]))
			if s[needExamBeginIndex] != s[needExamEndIndex] {
				continue OuterLoop
			}
			needExamBeginIndex++
			needExamEndIndex--
		}
		// reach here, it's a Palindrome
		if prefixLen == 0 {
			return s
		}
		// fmt.Println("strLen-prefixLen-1", strLen-prefixLen-1, strLen, prefixLen)
		return reverse(s[strLen-prefixLen:]) + s

	}
	return reverse(s) + s
}

func main() {
	fmt.Println(shortestPalindrome("abcd")) // dcbabcd
	fmt.Println(shortestPalindrome("aacecaaa")) // aaacecaaa
	fmt.Println(shortestPalindrome("aca")) // aca
}
