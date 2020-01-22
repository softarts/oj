package com.zhourui.codech

// +T 允许子类型
// Option

//case class 会自动生成apply方法，从而省去new操作
case class TreeNode(value : Int, left :TreeNode, right : TreeNode)

object Tree {
  def build(lines: IndexedSeq[IndexedSeq[String]]) = {
    def recurse(lines: IndexedSeq[IndexedSeq[String]]): IndexedSeq[TreeNode] = lines match {
      // 只剩下头部了，尾部为空,將頭部轉化爲treenode
      case line +: IndexedSeq() => {
        line.map{
          case ("N") => null
          case (v) => TreeNode(v.toInt,null,null) // 如果是 _=>就不行,必須括起來
        }
      }

      // +: 用提取的头部 +:(组合) 尾部的字符串表示 一个seq，对尾部进行recurse
      //第一次先进来 line = 1, rest = 23 456
      case line +: rest => {
        val prevTrees = recurse(rest)
        //scala.AnyRef 下面的zipped，把2个元素并在一起
        (line.filterNot(_==null), prevTrees.sliding(2).toIndexedSeq).zipped
          //Option有两个子类别，Some和None
          .map{
            case (v, IndexedSeq(left, right)) =>
              TreeNode(v.toInt, left, right)
          }
      }
      //返回一個空的array
      case _ => IndexedSeq.empty
    }
    recurse(lines).headOption
  }
}

