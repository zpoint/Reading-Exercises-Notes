package main

import "fmt"

var IMAX int = (1 << 31) - 1
var IMIN int = -(1 << 31)

func Reverse(x int) int {
	var minus bool = false
	if x < 0 {
		minus = true
		x = -x
	}

	var result int = 0
	for x > 0 {
		mod := x % 10
		x /= 10
		result = result * 10 + mod
	}
	if minus {
		result = -result
	}
	if result > IMAX || result < IMIN {
		return 0
	}
	return result
}

func main() {
	fmt.Println(Reverse(-1))
	fmt.Println(Reverse(1<<31))
	fmt.Println(Reverse(1234))
	fmt.Println(Reverse(1534236469))
}