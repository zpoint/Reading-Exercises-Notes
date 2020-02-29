package main

import (
	"container/list"
	"fmt"
)

func insert() {
	l := list.New()
	// 尾部添加
	l.PushBack("canon")
	// 头部添加
	l.PushFront(67)
	// 尾部添加后保存元素句柄
	element := l.PushBack("fist")
	// 在fist之后添加high
	l.InsertAfter("high", element)
	// 在fist之前添加noon
	l.InsertBefore("noon", element)
	fmt.Printf("%T\n", *element)
	// 使用
	l.Remove(element)

}

func traverse() {
	l := list.New()
	// 尾部添加
	l.PushBack("canon")
	// 头部添加
	l.PushFront(67)
	for i := l.Front(); i != nil; i = i.Next() {
		fmt.Println(i.Value)
	}
}

func main() {
	// insert()
	traverse()
}
