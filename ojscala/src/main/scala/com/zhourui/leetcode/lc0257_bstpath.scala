package com.zhourui.leetcode
import com.zhourui.codech._

//Given a binary tree, return all root-to-leaf paths.
//
//Note: A leaf is a node with no children.
//
//Example:
//
//Input:
//
//1
///   \
//2     3
//\
//5
//
//Output: ["1->2->5", "1->3"]
//
//Explanation: All root-to-leaf paths are: 1->2->5, 1->3

package lc0257 {

  import scala.collection.mutable.ArrayBuffer

  object Solution {
    def binaryTreePaths(root: TreeNode): List[String] = {
      val tmp = ArrayBuffer[Int]()
      val ret =ArrayBuffer[ArrayBuffer[Int]]()
      helper(root, tmp, ret)
      ret.toList.map({
        x=>x.mkString("->")
      })
    }

    def helper(node:TreeNode,tmp:ArrayBuffer[Int],ret:ArrayBuffer[ArrayBuffer[Int]]): Unit = {
      if (node==null) {
        return
      }

      tmp += node.value

      if (node.left == null && node.right==null) {
          ret += tmp.clone()
      } else {
        helper(node.left, tmp, ret)
        helper(node.right, tmp, ret)
      }
      tmp.remove(tmp.length-1)
    }
  }

  class Test extends BaseExtension {
    def init {
      val t1 = Tree.build(IndexedSeq("1","2 3","5 N N N"))
      println(Solution.binaryTreePaths(t1))
    }
    val name = "257 binary tree path"
  }
}
