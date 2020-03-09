package main

import (
	"fmt"
	"reflect"
)

func canNotSet() {
	var x float64 = 3.4
	p := reflect.ValueOf(&x) // Note: take the address of x.
	fmt.Println("type of p:", p.Type())
	fmt.Println("settability of p:", p.CanSet())
}

func YesCanSet() {
	var x float64 = 3.4
	p := reflect.ValueOf(&x) // Note: take the address of x.
	v := p.Elem()
	fmt.Println("settability of v:", v.CanSet())
}

func YesCanSet2() {
	var x float64 = 3.4
	p := reflect.ValueOf(&x) // Note: take the address of x.
	v := p.Elem()
	v.SetFloat(7.1)
	fmt.Println(v.Interface())
	fmt.Println(x)
}

func structEle() {
	type T struct {
		A int
		B string
	}
	t := T{23, "skidoo"}
	s := reflect.ValueOf(&t).Elem()
	typeOfT := s.Type()
	for i := 0; i < s.NumField(); i++ {
		f := s.Field(i)
		fmt.Printf("%d: %s %s = %v\n", i,
			typeOfT.Field(i).Name, f.Type(), f.Interface())
	}
}

func main() {
	canNotSet()
	YesCanSet()
	YesCanSet2()
	structEle()
}
