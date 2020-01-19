package com.zhourui.codech

import scala.beans.BeanProperty

class ListNode(var _x:Int = 0) {
  @BeanProperty var next: ListNode = _  //自动生成4个方法
    @BeanProperty var x: Int = _x

    //assit ctor
    def this(_x: Int, next: ListNode) = {
      this(_x)  // must call other ctor(main or assit)
      this.next = next
    }

    override def toString: String = {
      val sb = new StringBuilder
      sb ++= x.toString
      var p = this.next
      while (p!=null) {
        sb++="->" + p.x.toString
        p = p.next
      }
      sb.toString
    }
  }

  // companion object
  object ListNode {
    def apply(nums:Int*):ListNode = { //可变参数 P30
      // 创建一个linkedlist
      if (nums.isEmpty) null else {
        // _ 代表当前的num, reduceRight(参数1表示上一次的值？res表示本次,然后node 作为返回值
        nums.map(new ListNode(_)).reduceRight((node, res) => {
          node.next = res
          node
        })
      }
    }
  }


//class ListNode(var _x:Int = 0) {
//  var next: ListNode = _
//  var x: Int = _x
//
//  //assit ctor
//  def this(_x: Int, next: ListNode) = {
//    this(_x)  // must call other ctor(main or assit)
//    this.next = next
//  }
//
//  override def toString: String = {
//    val sb = new StringBuilder
//    sb ++= x.toString
//    var p = this.next
//    while (p!=null) {
//      sb++="->" + p.x.toString
//      p = p.next
//    }
//    sb.toString
//  }
//}
//
////
//object ListNode {
//  def apply(nums:Int*):ListNode = { //?
//    if (nums.isEmpty) null else {
//      // _ 代表当前的num, reduceRight(参数1表示上一次的值？res表示本次,然后node 作为返回值
//      nums.map(new ListNode(_)).reduceRight((node, res) => {
//        node.next = res
//        node
//      })
//    }
//  }
//}
/*object Test1 {
  def main(args:Array[String]): Unit ={
    var head:ListNode = ListNode(1,2,3,4,5)
    println(head)
  }
}*/


/*
package cons

sealed trait ConsInterface[+A] {
    def value: A
    def next: ConsInterface[A]
}

case class Cons[+A] (val value: A, val next: ConsInterface[A]) extends ConsInterface[A] {
    override def toString = s"head: $value, next: $next"
}

object NilCons extends ConsInterface[Nothing] {
    def value = throw new NoSuchElementException("head of empty list")
    def next = throw new UnsupportedOperationException("tail of empty list")
}

object ConsTutorialDriver extends App {
    val c1 = Cons(1, NilCons)
    val c2 = Cons(2, c1)
    val c3 = Cons(3, c2)
    println(c1)
    println(c2)
    println(c3)
}
 */