package main
import (
	"fmt"
	"strings"
)
// 字符串处理函数，传入字符串切片和处理链
func StringProccess(list1 []string, chain1 []func(string) string) {
	// 遍历每一个字符串
	for index, str := range list1 {
		// 第一个需要处理的字符串
		result := str
		// 遍历每一个处理链
		for _, proc := range chain1 {
			// 输入一个字符串进行处理，返回数据作为下一个处理链的输入。
			result = proc(result)
		}
		// 将结果放回切片
		list1[index] = result
	}
}
// 自定义的移除前缀的处理函数
func removePrefix(str string) string {
	return strings.TrimPrefix(str, "go")
}
func main() {
	// 待处理的字符串列表
	list2 := []string{
		"go scanner",
		"go parser",
		"go compiler",
		"go printer",
		"go formater",
	}
	// 处理函数链
	chain2 := []func(string) string{
		removePrefix,
		strings.TrimSpace,
		strings.ToUpper,
	}
	// 处理字符串
	StringProccess(list2, chain2)
	// 输出处理好的字符串
	for _, str := range list2 {
		fmt.Println(str)
	}
}
