package main

import "fmt"

type data int

func(d data)String()string{
	return fmt.Sprintf("data:%d\n",d)
}

func main() {
	var d data=15
	var x interface{} =d

	if n,ok:=x.(fmt.Stringer);ok{  // 转换为更具体的接口类型
		fmt.Printf("here\n")
		fmt.Printf("%T\n", n)
		fmt.Print(ok);
		fmt.Printf("\ndone\n")
	}

	if d2,ok:= x.(data);ok{        // 转换回原始类型
		fmt.Printf("here2\n")
		fmt.Printf("%T\n", d2);
		fmt.Println(d2)
	}

	e:=x.(error)           // 错误:main.data is not error
	fmt.Println(e)
}
