package main
import (
	"fmt"
)

type SuperInner struct {
	z int
}

type INNER struct {
	x int
	SuperInner
}

type AA struct {
	a int
}
type BB struct {
	a int
	INNER
}

type C struct {
	AA
	BB
}

func main() {
	c := &C{}
	c.AA.a = 1

	fmt.Println(c)
	fmt.Printf("hello", c.x)
	fmt.Printf("hello", c.z)
}
