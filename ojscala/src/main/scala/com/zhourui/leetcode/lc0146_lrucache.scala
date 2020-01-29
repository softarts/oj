package com.zhourui.leetcode
import com.zhourui.codech._
import scala.collection.mutable._

package lc0146 {
  class LRUCache(_capacity: Int) {

    val hm = HashMap[Int, Int]()
    val lb = ListBuffer.empty[Int]
    val c = _capacity

    def get(key: Int): Int = {
      if (hm.contains(key)) {
        val i = lb.indexOf(key)  // could be slow? O(N)?
        lb.remove(i)
        lb += key
        hm(key)
      } else {
        -1
      }

    }

    def put(key: Int, value: Int) {
      if (hm.contains(key)) {
        val i = lb.indexOf(key)  // could be slow? O(N)?
        lb.remove(i)
        lb += key
        hm(key) = value
      } else {
        if (hm.size == c) {
          val lk = lb.head
          hm.remove(lk)
          lb.remove(0)
        }
        hm(key) = value
        lb += key
      }
    }
  }

  class Test extends BaseExtension {
    def init {
      val lru = new LRUCache(2)
      lru.put(1,1)
      lru.put(2,2)
      println(lru.get(1) == 1)
    }

    val name = "146 LRU chache"
  }

  /**
   * Your LRUCache object will be instantiated and called as such:
   * var obj = new LRUCache(capacity)
   * var param_1 = obj.get(key)
   * obj.put(key,value)
   */


}
