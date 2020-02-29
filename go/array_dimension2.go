package main
import "fmt"

func main() {
	//声明一个二维切片
	var slice [][]int
	//为二维切片赋值
	slice = [][]int{{10}, {100, 200}}
	/*
	// 声明一个二维整型切片并赋值
	slice := [][]int{{10}, {100, 200}}
	 */
	fmt.Println(len(slice[0]), len(slice[1]))
	fmt.Printf("%T, %T\n", slice[0], slice[1])
}
