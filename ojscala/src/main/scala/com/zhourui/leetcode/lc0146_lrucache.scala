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


    var head:Node = null
    var tail:Node = null
    val hm = HashMap[Int, Node]()
    val c = _capacity

    def addToHead(cur:Node): Unit = {
      if (head!=null) {
        head.prev = cur
      } else {
        tail = cur
      }
      cur.prev = null
      cur.next = head
      head = cur
    }

    // cur not null
    def remove(cur:Node): Unit = {
      if (cur.prev!=null) { // it is Not head
        cur.prev.next = cur.next
      } else {
        head = cur.next
      }

      if (cur.next!=null) { // not tail
        cur.next.prev = cur.prev
      } else {
        tail = cur.prev
      }
    }

    def get(key: Int): Int = {
      if (hm.contains(key)) {
        val node = hm(key)
        remove(node)
        addToHead(node)
        node.v.v
      } else { // not found
        -1
      }
    }

    def put(key: Int, value: Int) {
      if (hm.contains(key)) {
        val node = hm(key)
        remove(node)
        addToHead(node)
        node.v.v = value
      } else {
        if (hm.size == c) {
          val old = tail
          if (old!=null) {
            remove(old)
            hm.remove(old.v.k)
          }
        }
        val node = Node(KV(key,value),null,null)
        hm(key) = node
        addToHead(node)
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

//  ["LRUCache","put","put","get","put","get","put","get","get","get"]
//  [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
  class Test2 extends BaseExtension {
    def init {
      val lru = new LRUCache2(2)
//      lru.put(1,1)
//      lru.put(2,2)
//      println(lru.get(1) == 1)
//      lru.put(3,3)
//      println(lru.get(2) == -1)
//      lru.put(4,4)
//      println(lru.get(1) == -1)
//      println(lru.get(3) == 3)
//      println(lru.get(4) == 4)

//        ["LRUCache","put","put","put","put","get","get"]
//        [[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]
      lru.put(2,1)
      lru.put(1,1)
      lru.put(2,3)
      lru.put(4,1)
      println(lru.get(1) == -1)
      println(lru.get(2) == 3)
    }
    val name = "146 LRU chache xxxx"
  }

  /**
   * Your LRUCache object will be instantiated and called as such:
   * var obj = new LRUCache(capacity)
   * var param_1 = obj.get(key)
   * obj.put(key,value)
   */


}
