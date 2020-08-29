package main

import "fmt"

func judgeCircle(moves string) bool {
	hor, vert := 0, 0
	for _, char := range moves {
		if char == 'L' {
			hor += 1
		} else if char == 'R' {
			hor -= 1
		} else if char == 'U' {
			vert += 1
		} else if char == 'D' {
			vert -= 1
		}
	}
	return hor == 0 && vert == 0
}

func main() {
	fmt.Println(judgeCircle("LRLR"))
}
