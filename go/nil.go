package main
import (
	"fmt"
	"unsafe"
)

func ptr() {
	var arr []int
	var num *int
	fmt.Printf("%p\n", arr)
	fmt.Printf("%p\n", num)
}

func compare() {
	var m map[int]string
	var ptr *int
	/*
	./nil.go:16:15: invalid operation: m == ptr (mismatched types map[int]string and *int)
	fmt.Printf(m == ptr)
	 */
	print()
	fmt.Printf("%T\n%T\n", m, ptr)

	var s1 []int
	var s2 []int
	/*
	invalid operation: s1 == s2 (slice can only be compared to nil)
	fmt.Printf(s1 == s2)
	 */

	fmt.Println(s1 == nil)
	fmt.Println(s2 == nil)

}

func value() {
	var m map[int]string
	var ptr *int
	var c chan int
	var sl []int
	var f func()
	var i interface{}
	fmt.Printf("%#v\n", m)
	fmt.Printf("%#v\n", ptr)
	fmt.Printf("%#v\n", c)
	fmt.Printf("%#v\n", sl)
	fmt.Printf("%#v\n", f)
	fmt.Printf("%#v\n", i)
}

func sizeof() {
	var p *struct{}
	fmt.Println( unsafe.Sizeof( p ) ) // 8
	var s []int
	fmt.Println( unsafe.Sizeof( s ) ) // 24
	var m map[int]bool
	fmt.Println( unsafe.Sizeof( m ) ) // 8
	var c chan string
	fmt.Println( unsafe.Sizeof( c ) ) // 8
	var f func()
	fmt.Println( unsafe.Sizeof( f ) ) // 8
	var i interface{}
	fmt.Println( unsafe.Sizeof( i ) ) // 16
}

func main() {
	fmt.Printf("%T\n", nil)
	/*
	./nil.go:7:7: use of untyped nil
	print(nil)
	 */
	ptr()
	compare()

	value()
	sizeof()
}
