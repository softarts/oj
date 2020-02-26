package com.zhourui.leetcode
import com.zhourui.codech._

//Remove all elements from a linked list of integers that have value val.
//
//Example:
//
//Input:  1->2->6->3->4->5->6, val = 6
//Output: 1->2->3->4->5

package lc203_remove_linkedlist_element {
  /**
   * Definition for singly-linked list.
   * class ListNode(var _x: Int = 0) {
   *   var next: ListNode = null
   *   var x: Int = _x
   * }
   */
  object Solution {
    def removeElements(head: ListNode, `val`: Int): ListNode = {
      val dummy = ListNode(0)
      dummy.next = head
      var prev = dummy
      var cur = head
      while (cur!=null) {
        if (cur.x != `val`) {
          prev.next = cur
          prev = cur
        } else {
          prev.next = null
        }
        cur = cur.next
      }
      dummy.next
    }
  }
}
