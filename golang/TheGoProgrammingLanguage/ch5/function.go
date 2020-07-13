//recursion func
package main

import "fmt"

//TreeNode this is a struct
type TreeNode struct {
	Value       int64
	Left, Right *TreeNode
}

//TraverseBinaryTree this is a function
func TraverseBinaryTree(node *TreeNode) {
	if node == nil {
		return
	}

	//fmt.Printf("node %v\n", node.Value)
	if node.Left != nil {
		TraverseBinaryTree(node.Left)
	}

	if node.Right != nil {
		TraverseBinaryTree(node.Right)
	}
}

//GeneratorTree input []int64
func GeneratorTree(arr []int64) *TreeNode {
	if len(arr) == 0 {
		return nil
	}
	treeNodeArray := make([]*TreeNode, len(arr))
	for i := 0; i < len(arr); i++ {
		treeNodeArray[i] = &TreeNode{Value: arr[i]}
	}

	for i := 0; i < len(treeNodeArray)/2; i++ {
		treeNodeArray[i].Left = treeNodeArray[2*i+1]
		if 2*i+2 < len(treeNodeArray) {
			treeNodeArray[i].Right = treeNodeArray[2*i+2]
		}
	}
	return treeNodeArray[0]
}

func recursion(n uint64) uint64 {
	if n <= 1 {
		return 0
	}
	if n <= 2 {
		return 1
	}
	return recursion(n-1) + recursion(n-2)
}

func main() {
	array := []int64{10: 100}
	treenode := GeneratorTree(array)
	TraverseBinaryTree(treenode)
	ret := recursion(10)
	fmt.Println(ret)
}
