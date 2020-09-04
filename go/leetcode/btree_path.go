package main

import "strconv"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

var FinalString []string = make([]string, 0)

func DfsTreePath(node *TreeNode, parentPath string) {
	if parentPath == "" {
		parentPath = strconv.Itoa(node.Val)
	} else {
		parentPath += "->" + strconv.Itoa(node.Val)
	}

	if node.Left == nil && node.Right == nil {
		FinalString = append(FinalString, parentPath)
		return
	}
	if node.Left != nil {
		DfsTreePath(node.Left, parentPath)
	}
	if node.Right != nil {
		DfsTreePath(node.Right, parentPath)
	}
}

func binaryTreePaths(root *TreeNode) []string {
	FinalString = FinalString[:0]
	if root == nil {
		return FinalString
	}
	DfsTreePath(root, "")
	return FinalString
}

func main() {
	binaryTreePaths()
}