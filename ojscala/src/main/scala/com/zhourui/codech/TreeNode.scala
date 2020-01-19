package com.zhourui.codech

// +T 允许子类型
// Option

case class TreeNode[+T](value : T, left :Option[TreeNode[T]], right : Option[TreeNode[T]])

class Tree {

  def buildTree[T](lines: IndexedSeq[IndexedSeq[T]]) = {
    def recurse[T](lines: IndexedSeq[IndexedSeq[T]]): IndexedSeq[TreeNode[T]] = lines match {
    case line +: IndexedSeq() => line.map(TreeNode(_, None, None))
    case line +: rest => {
    val prevTrees = recurse(rest)
    (line, prevTrees.sliding(2).toIndexedSeq).zipped
    .map{case (v, IndexedSeq(left, right)) => TreeNode(v, Some(left), Some(right))}
  }
    case _ => IndexedSeq.empty
  }
    recurse(lines).headOption
  }
}

//val input = """1
//2 3
//4 5 6""".stripMargin
//
//val lines = input.lines.map(_.filterNot(_ == ' ').toIndexedSeq).toIndexedSeq
////Vector(Vector(1), Vector(2, 3), Vector(4, 5, 6))
//
//val result = buildTree(lines)

//def CREATE_TREE[T](lines:IndexedSeq) = {
//
//}