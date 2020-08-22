/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

var AddrHeightMap map[*TreeNode]uint32 = make(map[*TreeNode]uint32)

func getHeight(node* TreeNode) uint32 {
	if node == nil {
		return 0
	}
	height, ok := AddrHeightMap[node]
	if ok {
		return height
	}
	var res uint32
	var LeftHeight uint32 = getHeight(node.Left)
	var RightHeight uint32 = getHeight(node.Right)
	if LeftHeight > RightHeight {
		res = LeftHeight + 1
	} else {
		res = RightHeight + 1
	}
	AddrHeightMap[node] = res
	return res
}

func nodeIsBalance(node* TreeNode) bool {
	if node == nil {
		return true
	}
	res := getHeight(node.Left) -  getHeight(node.Right)
	// fmt.Println("val: ", root.Val, "Left", root.Left, "Right", root.Right, "left height", getHeight(root.Left), "right height", getHeight(root.Right), "res", res)
	return res <= 1 || (res >= math.MaxUint32)
}

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}

	if !nodeIsBalance(root) {
		return false
	}
	if !isBalanced(root.Left) || !isBalanced(root.Right) {
		return false
	}
	return true
}

func main() {
	/*
	      1
	   /    \
	(3)2      2(3)
	/  \     /  \
  (2)3  nil nil 3(2)
   / \         / \
  (1)4 nil    nil 4(1)

	 */
	var top TreeNode = TreeNode{3, nil, nil}
	var right1 TreeNode = TreeNode{2, nil, nil}
	top.Right = &right1
	var right11 TreeNode = TreeNode{3, nil, nil}
	right1.Right = &right11
	fmt.Println("isBalanced(&top)", isBalanced(&top))
}