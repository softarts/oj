package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.ListNode;

// 使用O(1)的话，使用快慢指针
// 比cpp版本实现得还好

public class Lc0141_listcycle extends BaseSolution {
    public class Solution {
        public boolean hasCycle(ListNode head) {
            ListNode fast=head,slow=head;
            while (fast!=null && fast.next!=null) {
                fast = fast.next.next;
                slow = slow.next;
                if (fast==slow) {
                    return true;
                }
            }
            return false;
        }
    }
}
