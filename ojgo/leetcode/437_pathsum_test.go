package leetcode

/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).


*/
// 统计有多少条path的和是target
// 由于每个node都可能会重置，所以需要对left，right都分别递归处理
// 即每个node都可能是一个新的parent,来计算pathm
// 这个做法有问题，因为需要每一个node进行reset,所以targetsum不能受影响
// func pathSum(root *TreeNode, targetSum int) int {
// 	return dfs(root, targetSum, 0)
// }

// func dfs(root *TreeNode, targetSum int, indent int) int {
// 	if root == nil {
// 		return 0
// 	}
// 	for i := 0; i < indent; i++ {
// 		fmt.Print(" ")
// 	}
// 	fmt.Print(root.Val)

// 	var count = 0
// 	if root.Val == targetSum {
// 		count = 1
// 		fmt.Println(" -> found")
// 	} else {
// 		fmt.Println(" ")
// 	}
// 	return count + dfs(root.Left, targetSum-root.Val, indent+1) + dfs(root.Right, targetSum-root.Val, indent+1) +
// 		dfs(root.Left, targetSum, 0) + dfs(root.Right, targetSum, 0)

// }

// 10 -> 10
//  5 -> 15
//   3 -> 18
//    3 -> 21
//    -2 -> 16
//   2 -> 17
//    1 -> 18
//  -3 -> 7
//   11 -> 18
// 5 -> 5
//  3 -> 8 Found!
//   3 -> 11
//   -2 -> 6
//  2 -> 7
//   1 -> 8 Found!
// 3 -> 3
//  3 -> 6
//  -2 -> 1
// 3 -> 3
// -2 -> -2
// 2 -> 2
//  1 -> 3
// 1 -> 1
// -3 -> -3
//  11 -> 8 Found!
// 11 -> 11
func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}
	return dfs(root, 0, sum, 0) + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}

func dfs(node *TreeNode, prev int, target int, indent int) int {
	if node == nil {
		return 0
	}

	current := prev + node.Val
	var count = 0
	if current == target {
		count = 1
	}

	// for i := 0; i < indent; i++ {
	// 	fmt.Print(" ")
	// }
	// fmt.Printf("%d -> %d", node.Val, current)
	// if current == target {
	// 	fmt.Println(" Found!")
	// } else {
	// 	fmt.Println(" ")
	// }

	return count + dfs(node.Left, current, target, indent+1) + dfs(node.Right, current, target, indent+1)
}
