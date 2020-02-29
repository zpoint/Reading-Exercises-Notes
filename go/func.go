package main

func GetData(a int, b int) (int, int) {
	if a > b {
		return a, b
	}
	return b, a
}

func calc(a, b int) int {
	var c int
	c = a * b
	var x int
	x = c * 10
	return x
}

func main() {
	GetData(3, 4)
}
