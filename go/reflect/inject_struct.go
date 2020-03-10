package main
import (
	"fmt"
	"github.com/codegangsta/inject"
)

type S11 interface{}
type S22 interface{}

type Staff struct {
	Name    string  `inject`
	Company S11     `inject`
	Level   S22     `inject`
	Age     int     `inject`
}

func main() {
	//创建被注入实例
	s := Staff{}
	//控制实例的创建
	inj := inject.New()
	//初始化注入值
	inj.Map("tom")
	inj.MapTo("tencent", (*S11)(nil))
	inj.MapTo("T4", (*S22)(nil))
	inj.Map(23)
	//实现对 struct 注入
	inj.Apply(&s)
	//打印结果
	fmt.Printf("s ＝ %v\n", s)
}
