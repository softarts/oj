package com.zhourui.leetcode
import com.zhourui.codech._

package lc0101_symmetric_tree {
  object Solution {
    def isSymmetric(root: TreeNode): Boolean = {
      root match {
        case (node ==null) => true
        case (node) => {
          node.left != null && node.right!=null && node.left.value == node.right.value && isSymmetric(node.left)  && isSymmetric(node.right)
        }
      }
    }
  }
}
