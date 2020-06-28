package main

import "fmt"

var container = []string{"one", "two", "three"}

func main() {
	container := map[int]string{0: "one", 1: "two", 2: "three"}
	fmt.Printf("The element is %q.\n", container[1])
	value, ok := interface{}(container).([]string)
	fmt.Println("value: ", value, " ok: ", ok)

	s3 :=  []int{0,1,3,4,5}
	s4 := s3[:2]
	s5 := s4[:3]
	s4 = append(s4, 55)
	fmt.Println("cap s3: ", cap(s3))
	fmt.Println("s3: ", s3, "s4: ", s4, "s5", s5)
	s3[0] = 666
	fmt.Println("s3: ", s3, "s4: ", s4, "s5", s5)
	s5[0] = 777
	fmt.Println("s3: ", s3, "s4: ", s4, "s5", s5)
}
