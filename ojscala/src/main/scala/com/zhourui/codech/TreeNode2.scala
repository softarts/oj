package com.zhourui.codech

// +T 允许子类型
// Option
package treenode2 {
  //case class 会自动生成apply方法，从而省去new操作
  case class TreeNode[+T](value : T, left :Option[TreeNode[T]], right : Option[TreeNode[T]])

  object Tree {
    def buildTree[T](lines: IndexedSeq[IndexedSeq[T]]) = {
      //    def tt0(s:String) = {
      //      s match {
      //        case (v) =>  TreeNode(_: T, None, None)
      //      }
      //    }
      // match 爲何是 T=>TreeNode[T] 返回一個lambda?
      //    def makenode[T](v: T): String = v match {
      //      // 定义了一个递归方法，从Seq[T] 中构造String，T 为某种待定的类型。方法体是用来与输入的Seq[T] 相匹配。
      //      case "N" => "abcd" // 这里存在两个互斥的match 子句。第一个子句匹配非空的Seq，提取其头部（第一个元素）以及尾部（除头部以外，剩下的元素）。（Seq 有head 和tail 方法，但在这里，这两个标识符按case 子句的惯例被解释为变量。）在case 子句中，用提取的头部加上“+:”，以及尾部的字符串表示来构造一个字符串。尾部的字符串表示由调用seqToString 产生。
      //      case _ => TreeNode(_, None, None)
      //    }

      //    case line +: IndexedSeq() => {
      //      //line.map (TreeNode(_, None, None))
      //      line.map{
      //        v=>
      //          v match
      //          {
      //            case ("N") => None
      //            case (v) => TreeNode(v,None,None)
      //          }
      //      }
      //    } // 爲何以上會出現product with serializable

      def recurse[T](lines: IndexedSeq[IndexedSeq[T]]): IndexedSeq[Option[TreeNode[T]]] = lines match {
        // 只剩下头部了，尾部为空,將頭部轉化爲treenode

        case line +: IndexedSeq() => {
          line.map{
            case ('N') => None
            case (v) => Some(TreeNode(v,None,None)) // 如果是 _=>就不行
          }
        }

        // +: 用提取的头部 +:(组合) 尾部的字符串表示 一个seq，对尾部进行recurse
        //第一次先进来 line = 1, rest = 23 456
        case line +: rest => {
          val prevTrees = recurse(rest)
          //scala.AnyRef 下面的zipped，把2个元素并在一起
          (line.filterNot(_==None), prevTrees.sliding(2).toIndexedSeq).zipped
            //Option有两个子类别，Some和None
            .map{
              case (v, IndexedSeq(left, right)) =>
                Some(TreeNode(v, left, right))
            }
        }
        //返回一個空的array
        case _ => IndexedSeq.empty
      }

      recurse(lines).headOption
    }

    def buildTree0[T](lines: IndexedSeq[IndexedSeq[T]]) = {
      def recurse[T](lines: IndexedSeq[IndexedSeq[T]]): IndexedSeq[TreeNode[T]] = lines match {
        // 只剩下头部了，尾部为空
        case line +: IndexedSeq() => {
          line.map(TreeNode(_, None, None))
        }
        // +: 用提取的头部 +:(组合) 尾部的字符串表示 一个seq，对尾部进行recurse
        //第一次先进来 line = 1, rest = 23 456
        case line +: rest => {
          val prevTrees = recurse(rest)
          //scala.AnyRef 下面的zipped，把2个元素并在一起
          (line, prevTrees.sliding(2).toIndexedSeq).zipped
            //Option有两个子类别，Some和None
            .map{case (v, IndexedSeq(left, right)) => TreeNode(v, Some(left), Some(right))}
        }
        case _ => IndexedSeq.empty
      }
      recurse(lines).headOption
    }

    def main(args: Array[String]): Unit = {
      val input: String = """1
                            |2 3
                            |4 5 N 6""".stripMargin

      // lines 返回一个iterator[string], 然后构造一个数组的数组
      val lines = input.lines.map(_.filterNot(_ == ' ').toIndexedSeq).toIndexedSeq
      val result = buildTree(lines)
      println("exit")
    }
  }
}



//val lines = input.lines.map(_.filterNot(_ == ' ').toIndexedSeq).toIndexedSeq
////Vector(Vector(1), Vector(2, 3), Vector(4, 5, 6))
//

//def CREATE_TREE[T](lines:IndexedSeq) = {
//
//}