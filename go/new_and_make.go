package main

import "fmt"

func new_example() {
	var sum *int
	sum = new(int) //分配空间
	*sum = 98
	fmt.Println(*sum)

	type Student struct {
		name string
		age int
	}
	var s *Student
	var s2 Student
	s = new(Student) //分配空间
	s.name ="dequan"
	fmt.Println(s)
	s2.name = s.name
	fmt.Println(s2)
}

func make_example() {

}

func main() {
	new_example()
}