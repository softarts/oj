package leetcode

/*
验证是否二叉搜索树
做错了，注意需要populate祖先的值,把min和max传递下来
另外有些关于int64 边界的判断，正式面试中不太会有
*/

import (
	"math"
)

// func isValidBST(root *TreeNode) bool {
// 	var minv int64 =math.MinInt64
// 	var maxv int64 =math.MaxInt64
//     return dfs098(root, minv,maxv)
// }

// func dfs098(node *TreeNode, minv int64, maxv int64) bool {
// 	if node==nil {
// 		return true
// 	}
//     return  (int64(node.Val)<maxv && int64(node.Val)>minv &&
//     dfs(node.Left, minv, int64(node.Val)) &&
//             dfs(node.Right,  int64(node.Val), maxv)

// }

func isValidBST(root *TreeNode) bool {
    return dfs098(root, math.MinInt64, math.MaxInt64)
}

func dfs098(node *TreeNode, minv, maxv int64) bool {
	if node==nil {
		return true
	}
    return  int64(node.Val)<maxv && int64(node.Val)>minv &&
    dfs098(node.Left, minv, int64(node.Val)) &&
            dfs098(node.Right,  int64(node.Val), maxv)

}