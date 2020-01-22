package com.zhourui.leetcode
import com.zhourui.codech._

//if (p == null && q == null) {
//true
//} else if (p != null && q == null) {
//false
//} else if (p == null && q != null) {
//false
//} else if (p.value == q.value) {
//isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
//} else {
//false
//}
package lc0100 {

  object Solution {
    def isSameTree(p: TreeNode, q: TreeNode): Boolean = {
      if (p!=null && q!=null) {
        p.value == q.value && isSameTree(p.left,q.left) && isSameTree(p.right,q.right)
      } else {
        p == q
      }
    }
  }

  class Test extends BaseExtension {
    def init {

      //println(Solution.isSameTree(arr, 9).deep == Array(0, 1).deep)

    }
    val name = "100 sametree"
  }
}
