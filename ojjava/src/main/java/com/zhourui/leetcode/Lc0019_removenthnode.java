package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.ListNode;

// 做得不够漂亮
// 直接用fast and slow.考虑删除第一个和最后一个等边界情况
public class Lc0019_removenthnode extends BaseSolution {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode() {}
     *     ListNode(int val) { this.val = val; }
     *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     * }
     */
    class Solution {
        public ListNode removeNthFromEnd(ListNode head, int n) {
            ListNode fast = head, slow = head;
            while (n-- > 0) {
                fast = fast.next;
            }
            if (fast == null) { // delete the first one
                return head.next;
            }

            while (fast.next != null) {
                slow = slow.next;
                fast = fast.next;
            }
            //slow.next is to be deleted
            slow.next = slow.next.next;
            return head;
        }
    }
}
