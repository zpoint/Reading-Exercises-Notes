package main

import (
	"fmt"
	"math"
)

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

type Helper struct {
	node *TreeNode
	depth int
}

var Queue []Helper = make([]Helper, 0)
var MinDepthVal int = (1 << 31) - 1


func FindDepthForNode(node *TreeNode, depth int) {
	if node == nil {
		return
	}
	if node.Left == nil && node.Right == nil {
		// leaf
		if depth < MinDepthVal {
			MinDepthVal = depth
		}
	}

	if depth >= MinDepthVal {
		return
	}

	if node.Left != nil {
		Queue = append(Queue, Helper{node.Left, depth+1})
	}
	if node.Right != nil {
		Queue = append(Queue, Helper{node.Right, depth+1})
	}
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	Queue = append(Queue, Helper{root, 1})
	for len(Queue) > 0 {
		fmt.Println(Queue)
		h := Queue[0]
		Queue = Queue[1:]
		FindDepthForNode(h.node, h.depth)
	}
	return MinDepthVal
}

func main() {
	node2 := TreeNode{2, nil, nil}
	node1 := TreeNode{1, &node2, nil}
	fmt.Println(minDepth(&node1))
}