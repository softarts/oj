package com.zhourui.codech

class DoublyLinkedList {
  case class Node(v:Int,var prev:Node,var next:Node)

  var head:Node = null
  var tail:Node = null

  def push_back(node:Node): Unit = {
    node.prev = tail

    if (tail!=null) {
      tail.next = node
    } else {
      tail = node
      head = node
    }
  }

  def push_front(node:Node): Unit = {
    if (head!=null) {
      head.prev = node
    } else {
      tail = node
    }
    node.next = head
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
  }
}
