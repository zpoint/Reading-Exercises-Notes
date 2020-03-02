package main
import "fmt"

// 车轮
type Wheel2 struct {
	Size int
}
// 车
type Car2 struct {
	Wheel2
	// 引擎
	Engine2 struct {
		Power int    // 功率
		Type  string // 类型
	}
}
func main() {
	c := Car2{
		// 初始化轮子
		Wheel2: Wheel2{
			Size: 18,
		},
		// 初始化引擎
		Engine2: struct {
			Power int
			Type  string
		}{
			Type:  "1.4T",
			Power: 143,
		},
	}
	fmt.Printf("%+v\n", c)
}
