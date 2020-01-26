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
//    def isSameTree(p: TreeNode, q: TreeNode): Boolean = {
//      if (p!=null && q!=null) {
//        p.value == q.value && isSameTree(p.left,q.left) && isSameTree(p.right,q.right)
//      } else {
//        p == q
//      }
//    }
    def isSameTree(p: TreeNode, q: TreeNode): Boolean = {
        (p,q) match {
          case (p,q) if (p!=null && q!=null) => p.value == q.value && isSameTree(p.left,q.left) && isSameTree(p.right,q.right)
          case (p,q) => p==q
        }
    }
  }

  class Test extends BaseExtension {
    def init {
      {
        val t1 = Tree.build(IndexedSeq("1","2 3"))
        val t2 = Tree.build(IndexedSeq("1","2 3"))
        println(Solution.isSameTree(t1,t2) == true)
      }
      {
        val t1 = Tree.build(IndexedSeq("1","2"))
        val t2 = Tree.build(IndexedSeq("1","N 2"))
        println(Solution.isSameTree(t1,t2) == false)
      }
    }
    val name = "100 sametree"
  }
}
