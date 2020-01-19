package com.zhourui.leetcode
import com.zhourui.codech._


package lc002 {

  import com.sun.istack.internal.NotNull

  object Solution {
    def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
      var cur1 = l1
      var cur2 = l2
      val dummy = ListNode(0)
      var prev=dummy
      var carry = 0
      while (cur1!=null ||  cur2!=null || carry !=0) {
        val (s1,next1) = cur1 match {
          case null => (0,null)
          case _=> (cur1.x, cur1.next)
        }
        val (s2,next2) = cur2 match {
          case null => (0,null)
          case _=> (cur2.x,cur2.next)
        }
        val s = s1+s2+carry
        val node = ListNode(s % 10)
        prev.next = node
        prev=node
        carry=s/10
        cur1 = next1
        cur2=next2
      }
      dummy.next
    }
  }
  class Test extends BaseExtension {
    def init: Unit = {
      val h1:ListNode = ListNode(2,4,3)
      val h2:ListNode = ListNode(5,6,4)
      println(Solution.addTwoNumbers(h1,h2).toString=="7->0->8")
      //println(Solution.addTwoNumbers(h1,h2))
    }
    val name = "002 Add two number"
  }
}

/*
var carry = 0
var L1 = l1
var L2 = l2
var pre = new ListNode(0)
val head = pre
while (L1 != null || L2 !=null || carry !=0){
var value1,value2 = 0
if(L1 != null){
value1 = L1._x
L1 = L1.next
}
if(L2 != null){
value2 = L2._x
L2 = L2.next
}
val cur = new ListNode((value1+value2+carry) % 10)
carry = (value1+value2+carry) / 10
pre.next = cur
pre = cur
}
head.next

//============
object Solution {
    def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
        val dummyHead = ListNode(1)
        addNodes(dummyHead, l1, l2, 0)
        dummyHead.next
    }

    def addNodes(headNode: ListNode, l1: ListNode, l2: ListNode, carry: Int): Unit = {
        (l1, l2) match {
            case (null, null) => {
                if (carry == 1) headNode.next = ListNode(1)
                Unit
            }
            case _ => {
                val (value1, nextL1) = l1 match {
                    case null => (0, null)
                    case _ => (l1.x, l1.next)
                }
                val (value2, nextL2) = l2 match {
                    case null => (0, null)
                    case _ => (l2.x, l2.next)
                }
                val nextNode = ListNode((value1+value2+carry)%10)
                val nextCarry = (value1 + value2 + carry)/10
                headNode.next = nextNode
                addNodes(nextNode, nextL1, nextL2, nextCarry)
            }
        }
    }
}
 */