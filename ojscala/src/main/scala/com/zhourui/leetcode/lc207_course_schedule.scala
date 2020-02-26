package com.zhourui.leetcode
import com.zhourui.codech._

// new and apply
// Use the new keyword when you want to refer to a class's own constructor:
// 解法是 每个node(node)，1.它依赖的node个数(parent) 2.统计依赖它的node个数(son)，
// 一个node没有依赖其它节点，放入zeroInDegree
// 对zeroIndegree的node遍历，对每个依赖它的node都可以直接除去依赖

package lc207_course_schedule {

  import scala.collection.mutable.ArrayBuffer

  object Solution {
    def canFinish(numCourses: Int, prerequisites: Array[Array[Int]]): Boolean = {
      val inDegree = new Array[Int](numCourses)
      val neighbour = new Array[ArrayBuffer[Int]](numCourses).map(_=>new ArrayBuffer[Int]()) //必须初始化

      prerequisites.foreach(p=> {
        inDegree(p(0)) += 1
        neighbour(p(1)) += p(0)
      })

      var zeroInDegree = inDegree.zipWithIndex.filter(_._1 == 0).map(_._2).toList
      var canFinshNum = zeroInDegree.length
      while (zeroInDegree.nonEmpty) {
        val cur = zeroInDegree.head
        zeroInDegree = zeroInDegree.tail
        neighbour(cur).foreach(p=>{
          inDegree(p)-=1
          if (inDegree(p) == 0) {
            zeroInDegree :+= p
            canFinshNum+=1
          }
        })
      }
      canFinshNum == numCourses
    }
  }

  class Test extends BaseExtension {
    def init {
      val input = Array(Array(0,1),Array(1,2))
      println(Solution.canFinish(3,input) == true)
      //println(lru.get(1) == 1)
    }

    val name = "207 course schedule"
  }
}
