package com.zhourui.leetcode

import scala.collection.mutable._
//import scala.collection.immutable.{HashMap, HashSet}
package lc0049_groupanagram {



  object Solution {
    def groupAnagrams(strs: Array[String]):List [List[String]] = {
      val hm = HashMap[String,List[String]]()
      strs.foreach{
          case s if hm.contains(s.sorted) => hm(s.sorted) = hm(s.sorted) :+(s)
          case s => hm(s.sorted)=List[String](s)
      }
      hm.values.toList
    }
  }
}
