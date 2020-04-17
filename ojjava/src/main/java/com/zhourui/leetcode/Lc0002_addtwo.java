package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.ListNode;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class Lc0002_addtwo extends BaseSolution {
    class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode cur1=l1,cur2=l2;
            ListNode dummy = new ListNode(0);
            ListNode prev = dummy;
            var carry = 0;
            while (cur1!=null || cur2!=null ||  carry!=0) {
                var s = (cur1!=null?cur1.val:0) + (cur2!=null?cur2.val:0) + carry;
                carry = s / 10;
                var v = s % 10;
                ListNode node = new ListNode(v);
                prev.next = node;prev = node;
                cur1 = cur1!=null?cur1.next:null;
                cur2 = cur2!=null?cur2.next:null;
            }
            return dummy.next;
        }
    }
}
