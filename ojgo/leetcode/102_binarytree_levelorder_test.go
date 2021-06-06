package leetcode

import (
	"reflect"
	"testing"
	"github.com/softarts/ojgo/ojcommon"
)


type TreeNode=ojcommon.TreeNode

func levelOrder(root *TreeNode) [][]int {
	ret:=[][]int{} // slice并初始化
	stack:=[]*TreeNode{root} // 使用slice实现一个stack,先放入root
	count:=1
	for ;len(stack)>0; {
		levelCount:=0
		level := []int{}
		for i:=0;i<count;i++ {
			node:=stack[0]
			stack = stack[1:] // pop第一个element
			if node!=nil {
				level = append(level, node.Val)
				stack = append(stack, node.Left, node.Right)
				levelCount+=2
			}
		}
		if len(level)>0 {
			ret = append(ret, level)
		}
		count = levelCount
	}
	return ret
}

func Test102(t *testing.T) {
	var ret = levelOrder(nil)
	var exp = [][]int{}
	if !reflect.DeepEqual(ret, exp) {
		t.Errorf("Not Passed, got %v", ret)
	}
}