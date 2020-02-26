package com.zhourui.leetcode

import scala.collection.mutable.ArrayBuffer
// 与lc207类似，不过要给出顺序

class lc210_courseschedule2 {
  object Solution {
    def findOrder(numCourses: Int, prerequisites: Array[Array[Int]]): Array[Int] = {
      val inDegree = new Array[Int](numCourses)
      val neighbour = new Array[ArrayBuffer[Int]](numCourses).map(_=>new ArrayBuffer[Int]()) //必须初始化

      prerequisites.foreach(p=> {
        inDegree(p(0)) += 1
        neighbour(p(1)) += p(0)
      })

      val ans = ArrayBuffer[Int]()
      var zeroInDegree = inDegree.zipWithIndex.filter(_._1 == 0).map(_._2).toList
      var canFinshNum = zeroInDegree.length
      while (zeroInDegree.nonEmpty) {
        val cur = zeroInDegree.head
        ans += cur
        zeroInDegree = zeroInDegree.tail
        neighbour(cur).foreach(p=>{
          inDegree(p)-=1
          if (inDegree(p) == 0) {
            zeroInDegree :+= p
            canFinshNum+=1
          }
        })
      }
      canFinshNum match {
        case canFinshNum if canFinshNum == numCourses => ans.toArray
        case _ => Array()
      }
    }
  }
}
