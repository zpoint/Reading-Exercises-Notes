package main

import (
	"encoding/json"
	"fmt"
)

func main() {
	// 声明技能结构体
	type Skill struct {
		Name  string `json:"name,omitempty"`
		Level int    `json:"level"`
	}
	// 声明角色结构体
	type Actor struct {
		Name   string
		Age    int
		Skills []Skill
	}
	// 填充基本角色数据
	a := Actor{
		Name: "cow boy",
		Age:  37,
		Skills: []Skill{
			{Name: "", Level: 1},
			{Name: "Flash your dog eye"},
			{Name: "Time to have Lunch", Level: 3},
		},
	}
	result, err := json.Marshal(a)
	if err != nil {
		fmt.Println(err)
	}
	jsonStringData := string(result)
	fmt.Println(jsonStringData)
}