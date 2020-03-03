package main

import (
	"fmt"
	"time"
)

func strftime() {
	var layout string = "2006-01-02 15:04:05"
	var timeStr string = "2019-12-12 15:22:12"
	timeObj1, _ := time.Parse(layout, timeStr)
	fmt.Println(timeObj1)
	timeObj2, _ := time.ParseInLocation(layout, timeStr, time.Local)
	fmt.Println(timeObj2)
}

func ticker() {
	ticker := time.Tick(time.Second) //定义一个1秒间隔的定时器
	for i := range ticker {
		fmt.Println(i) //每秒都会执行的任务
		break
	}
}

func timestamp() {
	now := time.Now()            //获取当前时间
	timestamp1 := now.Unix()     //时间戳
	timestamp2 := now.UnixNano() //纳秒时间戳
	fmt.Printf("现在的时间戳：%v\n", timestamp1)
	fmt.Printf("现在的纳秒时间戳：%v\n", timestamp2)
}

func timeUnix() {
	now := time.Now()                  //获取当前时间
	timestamp := now.Unix()            //时间戳
	timeObj := time.Unix(timestamp, 0) //将时间戳转为时间格式
	fmt.Println(timeObj)
	year := timeObj.Year()     //年
	month := timeObj.Month()   //月
	day := timeObj.Day()       //日
	hour := timeObj.Hour()     //小时
	minute := timeObj.Minute() //分钟
	second := timeObj.Second() //秒
	fmt.Printf("%d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second)
	fmt.Println(now.Weekday().String())
}

func main() {
	now := time.Now() //获取当前时间
	fmt.Printf("current time:%+v\n", now)
	year := now.Year()     //年
	month := now.Month()   //月
	day := now.Day()       //日
	hour := now.Hour()     //小时
	minute := now.Minute() //分钟
	second := now.Second() //秒
	fmt.Printf("%d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second)

	timestamp()
	timeUnix()
	ticker()
	strftime()
}
