package com.zhourui.leetcode;

import com.zhourui.codech.*;

import java.util.Arrays;

public class Lc0876_middlelist extends BaseSolution{
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */
    class Solution {
        public ListNode middleNode(ListNode head) {
            ListNode ori = head;
            int length = 0;
            while (head!=null) {
                head=head.next;
                length +=1;
            }
            head = ori;
            int idx = 0;
            while (idx<length/2) {
                head = head.next;
                idx++;
            }
            return head;
        }
    }
    @Override
    public String name() {return "two sum";}

    @Override
    public boolean test() {
        return true;
    }
}
