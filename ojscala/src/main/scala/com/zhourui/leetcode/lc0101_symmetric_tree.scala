package com.zhourui.leetcode
import com.zhourui.codech._

package lc0101_symmetric_tree {
  object Solution {
    def isSymmetric(root: TreeNode): Boolean = {
      def compare(t1:TreeNode, t2:TreeNode):Boolean = {
        (t1,t2) match {
          case (t1, t2) if t1!=null && t2!=null  => t1.value==t2.value && compare(t1.left,t2.right) && compare(t1.right,t2.left)
          case (t1, t2) => {
            t1==null && t2==null
          }
        }
      }
      root match {
        case null=>true
        case _=>compare(root.left, root.right)
      }
    }
  }
}
