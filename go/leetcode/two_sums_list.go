package main

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var next int = 0
	var leftVal int = 0
	var rightVal int = 0
	var currVal int = 0
	var head *ListNode
	var prev *ListNode

	for l1 != nil || l2 != nil {
		if l1 != nil {
			leftVal = l1.Val
			l1 = l1.Next
		}  else {
			leftVal = 0
		}

		if l2 != nil {
			rightVal = l2.Val
			l2 = l2.Next
		} else {
			rightVal = 0
		}

		currVal = leftVal + rightVal + next
		next = 0
		if currVal >= 10 {
			next += 1
			currVal -= 10
		}
		curr := ListNode{Val : currVal, Next: nil}
		if head == nil {
			head = &curr
			prev = &curr
		} else {
			prev.Next = &curr
			prev = &curr
		}
	}
	if next > 0 {
		curr := ListNode{Val : next, Next: nil}
		prev.Next = &curr
		prev = &curr
	}
	return head
}

func main() {
	l1 := ListNode{Val: 5}
	l2 := ListNode{Val: 5}
	res := addTwoNumbers(&l1, &l2)
	fmt.Println("res", res)
}