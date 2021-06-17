package leetcode

/*
如何判断完全二叉树
思路 判断每层的个数, 这个有点费事,
直接用个marker?
*/

func isCompleteTree(root *TreeNode) bool {
	if root==nil {return false}
	q:=[]*TreeNode{root}
	var endMarker bool
	for len(q) != 0 {
		root, q = q[0], q[1:]
		
		//需要注意括号
		if endMarker && (root.Left!=nil || root.Right!=nil) {
			// endMarker appear but followed nodes
			return false
		}
		
		if root.Left==nil && root.Right!=nil {
			return false  // case 1
		}

		if (root.Left==nil && root.Right==nil) || root.Right==nil {
			endMarker = true
		}

		if root.Left!=nil {	q = append(q, root.Left)	}
		if root.Right!=nil { q = append(q, root.Right)	}
	}
	return true    
}


// if endMarker && (root.Left!=nil || root.Right!=nil) {
// 	// endMarker appear but followed nodes
// 	return false
// } 
// if root.Left==nil && root.Right==nil || root.Right==nil {
// 	endMarker = true
// }else if root.Left==nil{
// 	return false  // case 1
// }
