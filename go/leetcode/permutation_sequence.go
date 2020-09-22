package main

import "fmt"

func getPermutation(n int, k int) string {

}

func main() {
	// round_up((3+1) / 2(2!)) == 2
	// 3 % 2(2!) == 1

	// f(6(3!), 3) == 2
	// f(2(2!), 1) == 1
	// f(1(1!), 1) == 3
	fmt.Println(getPermutation(3, 3)) // 213
	// round_up((9+1) / 6(3!)) == 2
	// 9 % 6(3!) == 3

	// f(24(4!), 9) == 2
	// f(6(3!), 3) == 3
	// 3 % 2(2!) == 1
	// f(2(2!), 1) == 1
	// f(1(1!), 1) == 4

	fmt.Println(getPermutation(4, 9)) // 2314
}
