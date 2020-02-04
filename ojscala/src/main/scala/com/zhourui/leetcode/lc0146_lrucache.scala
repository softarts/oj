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


  class LRUCache2(_capacity: Int) {
    case class KV(k:Int,var v:Int)
    case class Node(v:KV,var prev:Node,var next:Node)

    //var head = Node(KV(-1,-1),null,null)
    var head:Node = null

    val hm = HashMap[Int, Node]()

    //val lb = ListBuffer.empty[Int]
    val c = _capacity

    def addToHead(cur:Node): Unit = {
      cur.prev = cur.next
      cur.next = head
      head = cur
    }

    def remove(cur:Node): Unit = {
      if (cur.prev!=null) { // it is Not head
        cur.prev = cur.next
      }
      head = cur.next
    }

    def get(key: Int): Int = {
      if (hm.contains(key)) {
        val node = hm(key)
        addToHead(node)
        node.v.v
      } else { // not found
        -1
      }
    }

    def put(key: Int, value: Int) {
      if (hm.contains(key)) {
        val node = hm(key)
        addToHead(node)
        node.v.v = value
      } else {

        if (hm.size == c) {
          val node = hm(key)

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
