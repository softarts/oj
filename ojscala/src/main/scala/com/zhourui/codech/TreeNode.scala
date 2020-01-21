package com.zhourui.codech

// +T 允许子类型
// Option

case class TreeNode[+T](value : T, left :Option[TreeNode[T]], right : Option[TreeNode[T]])

object Tree {
  def buildTree[T](lines: IndexedSeq[IndexedSeq[T]]) = {
    def recurse[T](lines: IndexedSeq[IndexedSeq[T]]): IndexedSeq[TreeNode[T]] = lines match {
        // +: 一个空seq，用提取的头部加上“+:”，以及尾部的字符串表示来构造一个seq
      case line +: IndexedSeq() => {
        line.map(TreeNode(_, None, None))
      }
        // +: 非空seq
      case line +: rest => {
        val prevTrees = recurse(rest)
        (line, prevTrees.sliding(2).toIndexedSeq).zipped
        .map{case (v, IndexedSeq(left, right)) => TreeNode(v, Some(left), Some(right))}
      }
      case _ => IndexedSeq.empty
    }
    recurse(lines).headOption
  }

  def main(args: Array[String]): Unit = {
    val input: String = """1
    |2 3
    |4 5 6""".stripMargin

    // 构造一个数组的数组
    val lines = input.lines.map(_.filterNot(_ == ' ').toIndexedSeq).toIndexedSeq
    val result = buildTree(lines)

  }
}


//val lines = input.lines.map(_.filterNot(_ == ' ').toIndexedSeq).toIndexedSeq
////Vector(Vector(1), Vector(2, 3), Vector(4, 5, 6))
//

//def CREATE_TREE[T](lines:IndexedSeq) = {
//
//}