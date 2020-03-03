package main

import (
	"fmt"
	"regexp"
	"strconv"
)

func replace() {
	//目标字符串
	searchIn := "John: 2578.34 William: 4567.23 Steve: 5632.18"
	pat := "[0-9]+.[0-9]+"          //正则
	f := func(s string) string{
		v, _ := strconv.ParseFloat(s, 32)
		return strconv.FormatFloat(v * 2, 'f', 2, 32)
	}
	if ok, _ := regexp.Match(pat, []byte(searchIn)); ok {
		fmt.Println("Match Found!")
	}
	re, _ := regexp.Compile(pat)
	//将匹配到的部分替换为 "##.#"
	str := re.ReplaceAllString(searchIn, "##.#")
	fmt.Println(str)
	//参数为函数时
	str2 := re.ReplaceAllStringFunc(searchIn, f)
	fmt.Println(str2)
}

func main() {
	buf := "abc azc a7c aac 888 a9c  tac"
	//解析正则表达式，如果成功返回解释器
	reg1 := regexp.MustCompile(`a.c`)
	if reg1 == nil {
		fmt.Println("regexp err")
		return
	}
	//根据规则提取关键信息
	result1 := reg1.FindAllStringSubmatch(buf, -1)
	for a, b := range result1 {
		fmt.Println("a: ", a)
		fmt.Println("b: ", b)
		fmt.Printf("%#v\n", b)
	}
	fmt.Println("result1 = ", result1)

	replace()
}