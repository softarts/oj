package com.zhourui.leetcode
import scala.collection.mutable._
import com.zhourui.codech._
package lca01_countingelement {
  object Solution {
    def countElements(arr: Array[Int]): Int = {
      //arr.zipWithIndex.groupBy(_._1).to
      //val a= arr.groupBy(_=>_)
      //val donuts: Seq[String] = Seq("Plain Donut", "Strawberry Donut", "Glazed Donut")
      //donuts.groupBy(_)
      //val donutsGroup: Map[Char, Seq[String]] = donuts.groupBy(_.
      // must be a lambda
      //val donutsGroup: Map[String, Seq[String]] = donuts.groupBy(x=>x)
      //val m:HashMap[Int,Int] = arr.groupBy(x=>x).mapValues(x=>x.length)

      //immutable can't cast to mutable hashmap
      val im= arr.groupBy(l => l).map(t => (t._1, t._2.length))
      //https://stackoverflow.com/questions/7938585/what-does-param-mean-in-scala
      //: _* is a special instance of type ascription which tells the compiler to treat a single argument of a sequence type as a variable argument sequence, i.e. varargs.
      val m:HashMap[Int,Int]  = collection.mutable.HashMap(im.toSeq: _*)

      arr.foldLeft(0){
        case (a,b) if (m.contains(b+1) && m(b+1)>0) => {
          m(b + 1) = m(b + 1) - 1
          a + 1
        }
        case (a,b) => a
      }
//
//      for (elem <- arr) {
//        if (m.contains(elem+1)) {
//          m(elem+1) = m(elem+1)-1
//        }
//      }
//      m.foreach {
//        case (a, b) =>
//          println(a, b)
//      }

    }
  }

  class Test3 extends BaseExtension {
    def init {
      println(Solution.countElements(Array(1,3,2,3,5,0))==3)
    }
    val name = "lc01 counting elements"
  }
}
