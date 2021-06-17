package leetcode

/*
思路，找出第k小的元素
应该没问题的，不知为何过不了
*/
var (
	idx int
	flag bool
	ans int
)

func kthSmallest(root *TreeNode, k int) int {
    dfs230(root, k)
	return ans
}


func dfs230(node *TreeNode, k int) {
	if node==nil || flag{		
		return 
	}

	dfs230(node.Left, k)
	idx++
	if idx == k {
		flag = true
		ans = node.Val
		return
	}
	dfs230(node.Right, k)
}
