package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
)

func main() {
	var w io.Writer
	w = os.Stdout
	f := w.(*os.File) // 成功: f == os.Stdout
	fmt.Printf("%T\n", f)
	c := w.(*bytes.Buffer) // 死机：接口保存*os.file，而不是*bytes.buffer
	fmt.Print(c)
}