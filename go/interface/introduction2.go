package main
import "fmt"

type stringer interface{
	string()string
}

type tester interface{
	stringer               // 嵌入其他接口
	test()
}

type data struct{}

func(*data)test() {
	fmt.Printf("in test\n")
}

func(*data)string()string{
	fmt.Printf("in string\n");
	return""
}

func main() {
	var d data

	var t tester= &d
	t.test()
	println(t.string())
}

