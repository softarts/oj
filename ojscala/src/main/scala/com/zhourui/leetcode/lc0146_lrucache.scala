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

// test case
//  ["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]
//  [[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]

//  [null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,-1,null,null,18,null,null,-1,null,null,null,null,null,18,null,null,-1,null,4,29,30,null,12,-1,null,null,null,null,29,null,null,null,null,17,22,18,null,null,null,-1,null,null,null,20,null,null,null,-1,18,18,null,null,null,null,20,null,null,null,null,null,null,null]
  class LRUCache3(_capacity: Int) {
    val hm = HashMap[Int, Node]()
    val dl = new DoublyLinkedList()
    val c = _capacity

    def get(key: Int): Int = {
      if (hm.contains(key)) {
        val node = hm(key)
        dl.erase(node)
        dl.push_front(node)
        node.v.v
      } else { // not found
        -1
      }
    }

    def put(key: Int, value: Int) {
      if (hm.contains(key)) {
        val node = hm(key)
        dl.erase(node)
        dl.push_front(node)
        node.v.v = value
      } else {
        if (hm.size == c) {
          val old = dl.tail
          if (old!=null) {
            dl.erase(old)
            hm.remove(old.v.k)
          }
        }
        val node = Node(KV(key,value),null,null)
        hm(key) = node
        dl.push_front(node)
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
      lru.put(2,1)
      lru.put(1,1)
      lru.put(2,3)
      lru.put(4,1)
      println(lru.get(1) == -1)
      println(lru.get(2) == 3)
    }
    val name = "146 LRU chache xxxx"
  }

  //  ["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]
  //  [[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]
  //  [null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,-1,null,null,18,null,null,-1,null,null,null,null,null,18,null,null,-1,null,4,29,30,null,12,-1,null,null,null,null,29,null,null,null,null,17,22,18,null,null,null,-1,null,null,null,20,null,null,null,-1,18,18,null,null,null,null,20,null,null,null,null,null,null,null]

  class Test3 extends BaseExtension {
    def init {
      val lru = new LRUCache3(10)
      lru.put(10,13)
      lru.put(3,17)
      lru.put(6,11)
      lru.put(10,5)
      lru.put(9,10)

      println(lru.get(1) == -1)
      println(lru.get(2) == 3)
    }
    val name = "146 LRU chache xxxx"
  }



}
