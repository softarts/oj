package com.zhourui.codech

// generate companion object
//case class Node(var v:Int,var prev:Node,var next:Node)
//covariant type occurs in contravariant position
//case class Node[+T](v:T,var prev:Node[T],var next:Node[T])

// https://stackoverflow.com/questions/43180310/covariant-type-a-occurs-in-contravariant-position-in-type-a-of-value-a/43180701
case class KV(k:Int,var v:Int)
case class Node(var v:KV,var prev:Node,var next:Node)

class DoublyLinkedList {
  var head:Node = null
  var tail:Node = null

  def push_back(node:Node): Unit = {
    node.prev = tail

    if (tail!=null) {
      tail.next = node
    } else {
      head = node
    }
    tail = node
  }

  def push_front(node:Node): Unit = {
    if (head!=null) {
      head.prev = node
    } else {
      tail = node
    }
    node.next = head
    node.prev = null
    head = node
  }

  def erase(node:Node): Unit = {
    val prev = node.prev
    if (prev != null) { // it is Not head
      prev.next = node.next
    } else {
      head = node.next
    }

    val next = node.next
    if (next != null) { // not tail
      node.next.prev = prev
    } else {
      tail = prev
    }

    node.prev = null  // 必须加上这个
    node.next = null
  }
}
