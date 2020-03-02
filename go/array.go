package main
import "fmt"

func print() {
	var team [3]string
	team[0] = "hammer"
	team[1] = "soldier"
	team[2] = "mum"
	for k, v := range team {
		fmt.Println(k, v)
	}
}

func equal() {
	a := [2]int{1, 2}
	b := [...]int{1, 2}
	c := [2]int{1, 3}
	// c = [2]int{5, 6}
	fmt.Println(a == b, a == c, b == c) // "true false false"
	d := [3]int{1, 2}
	fmt.Printf("%T\n", d)
	// fmt.Println(a == d) // 编译错误：无法比较 [2]int == [3]int
}

func arr2() {
	var q [3]int = [3]int{1, 2, 3}
	var r [3]int
	fmt.Println(r[2]) // "0"
	fmt.Println(q[2])
	/* 在数组的定义中，如果在数组长度的位置出现“...”省略号，
	则表示数组的长度是根据初始化值的个数来计算，因此，上面数组 z 的定义可以简化为
	 */
	z := [...]int{1, 2, 3}
	fmt.Printf("%T\n", z) // "[3]int"
	/*
	数组的长度是数组类型的一个组成部分，
	因此 [3]int 和 [4]int 是两种不同的数组类型，数组的长度必须是常量表达式，
	因为数组的长度需要在编译阶段确定

	q := [3]int{1, 2, 3}
	q = [4]int{1, 2, 3, 4} // 编译错误：无法将 [4]int 赋给 [3]int
	 */
}

func main() {
	var a[3]int             // 定义三个整数的数组
	fmt.Println(a[0])        // 打印第一个元素
	fmt.Println(a[len(a)-1]) // 打印最后一个元素
	// 打印索引和元素
	for i, v := range a {
		fmt.Printf("%d %d\n", i, v)
	}
	// 仅打印元素
	for _, v := range a {
		fmt.Printf("%d\n", v)
	}
	fmt.Printf("calling arr2\n")
	arr2()
	fmt.Printf("calling equal\n")
	equal()
	fmt.Printf("calling print\n")
	print()
}

