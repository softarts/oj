package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.ListNode;



//对listode进行shift,如果可以使用额外空间，很简单，放到arraylist中，然后重新整理
// 目前的做法就是先计算count,然后找到切分点，再决定要不要重新接驳

public class Lc0061_rotatelist extends BaseSolution {
    class Solution {
        public ListNode rotateRight(ListNode head, int k) {
            if (k==0||head==null) return head;

            ListNode ori=head;
            ListNode tail=null,prev=null;
            int count=0;
            while (head!=null) {
                tail = head;
                head=head.next;
                count++;
            }

            int steps=count-k%count;
            head = ori;
            prev = tail;
            while (steps>0) {
                prev = head;
                head=head.next;steps--;
            }

            prev.next = null; //safe
            if (head==null) {
                head = ori;
            } else if (head!=ori) {
                tail.next = ori;
            }
            return head;
        }
    }

    @Override
    public String name() {return "rotate list";}

    @Override
    public boolean test() {
        ListNode node=new ListNode(1);
        ListNode ret = new Lc0061_rotatelist.Solution().rotateRight(node, 1);
        return ret==node;
    }
}
