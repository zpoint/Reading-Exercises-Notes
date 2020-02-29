package main
import "fmt"

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

func add(x int, y int) int {return x + y}
func sub(x, y int) (z int) { z = x - y; return}
func first(x int, _ int) int { return x }
func zero(int, int) int { return 0 }

func namedRetValues() (a, b int) {
	a = 1
	b = 2
	return
}

func namedRetValues2() (a, b int) {
	a = 1
	return a, 2
}

func fire() {
	fmt.Println("fire")
}

func main() {
	GetData(3, 4)
	fmt.Printf("%T\n", add) // "func(int, int) int"
	fmt.Printf("%T\n", sub) // "func(int, int) int"
	fmt.Printf("%T\n", first) // "func(int, int) int"
	fmt.Printf("%T\n", zero) // "func(int, int) int"
	var f func() (int, int)
	f = namedRetValues
	f()
}
