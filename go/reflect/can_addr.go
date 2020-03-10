package main

import (
	"fmt"
	"reflect"
)

func SetPanic() {
	// 声明整型变量a并赋初值
	var a int = 1024
	// 获取变量a的反射值对象
	valueOfA := reflect.ValueOf(a)
	// 尝试将a修改为1(此处会发生崩溃)
	valueOfA.SetInt(1)
}

func setNoPanic() {
	// 声明整型变量a并赋初值
	var a int = 1024
	// 获取变量a的反射值对象(a的地址)
	valueOfA := reflect.ValueOf(&a)
	// 取出a地址的元素(a的值)
	valueOfA = valueOfA.Elem()
	// 修改a的值为1
	valueOfA.SetInt(1)
	// 打印a的值
	fmt.Println(valueOfA.Int())
}

func exportPanic() {
	type dog struct {
		legCount int
	}
	// 获取dog实例的反射值对象
	valueOfDog := reflect.ValueOf(dog{})
	// 获取legCount字段的值
	vLegCount := valueOfDog.FieldByName("legCount")
	// 尝试设置legCount的值(这里会发生崩溃)
	vLegCount.SetInt(4)
}

func exportNoPanic() {
	type dog struct {
		LegCount int
	}
	// 获取dog实例地址的反射值对象
	valueOfDog := reflect.ValueOf(&dog{})
	// 取出dog实例地址的元素
	valueOfDog = valueOfDog.Elem()
	// 获取legCount字段的值
	vLegCount := valueOfDog.FieldByName("LegCount")
	// 尝试设置legCount的值(这里会发生崩溃)
	vLegCount.SetInt(4)
	fmt.Println(vLegCount.Int())
}

func main() {
	x := 2 // value type variable?
	a := reflect.ValueOf(2) // 2 int no
	b := reflect.ValueOf(x) // 2 int no
	c := reflect.ValueOf(&x) // &x *int no
	d := c.Elem() // 2 int yes (x)

	fmt.Println(a.CanAddr()) // "false"
	fmt.Println(b.CanAddr()) // "false"
	fmt.Println(c.CanAddr()) // "false"
	fmt.Println(d.CanAddr()) // "true"

	setNoPanic()
	// exportPanic()
	exportNoPanic()
}
