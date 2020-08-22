package main

import "fmt"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type ListNode struct {
	Val int
	Next *ListNode
}

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func ListNode2Array(head *ListNode) []int {
	originHead := head
	var size uint32 = 0
	for head != nil {
		size += 1
		head = head.Next
	}
	slice := make([]int, size)
	for index := 0; originHead != nil; index += 1 {
		slice[index] = originHead.Val
		originHead = originHead.Next

	}
	return slice
}

func buildTree(slice []int) *TreeNode {
	if len(slice) == 0 {
		return nil
	}
	index := len(slice) / 2
	mid := slice[index]
	leftRange := slice[:index]
	rightRange := slice[index+1:]
	// fmt.Println("index", index, "slice", slice, "leftRange", leftRange, "rightRange", rightRange)
	leftNode := buildTree(leftRange)
	rightNode := buildTree(rightRange)
	node := new(TreeNode)
	node.Val = mid
	node.Left = leftNode
	node.Right = rightNode
	return node
}

func sortedListToBST(head *ListNode) *TreeNode {
	slice := ListNode2Array(head)
	return buildTree(slice)
}

func main() {
	var first ListNode = ListNode{Val: -10}
	var second ListNode = ListNode{Val: -3}
	first.Next = &second
	var third ListNode = ListNode{Val: 0}
	second.Next = &third
	var fourth ListNode = ListNode{Val: 5}
	third.Next = &fourth
	var fifth ListNode = ListNode{Val: 9}
	fourth.Next = &fifth

	sortedListToBST(&first)
}