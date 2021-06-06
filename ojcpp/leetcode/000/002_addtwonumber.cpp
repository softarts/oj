//
// Created by Rui Zhou on 28/3/18.
//

/*
 * https://leetcode.com/problems/add-two-numbers/description/
 *You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
 * order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace CODECH;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1=l1;
        ListNode *cur2=l2;
        ListNode *prev = nullptr, *head = nullptr;

        int r = 0;
        while (cur1 || cur2) {
            int s = (cur1?cur1->val:0) + (cur2?cur2->val:0) + r;

            ListNode * node = new ListNode(s%10);
            if (prev) {
                prev->next = node;
                prev = node;
            } else {
                head = node;
                prev = node;
            }

            r = s / 10;
            cur1 = cur1?cur1->next:nullptr;
            cur2 = cur2?cur2->next:nullptr;
        }

        if (r>0) {
            ListNode * node = new ListNode(r);
            if (prev)
                prev->next = node;
        }
        return head;
    }
};

DEFINE_CODE_TEST(002_add_twonumber)
{
    Solution obj;
    {
        ListNode *l1 = CREATE_LIST({2,4,3});
        ListNode *l2 = CREATE_LIST({5,6,4});
        VERIFY_CASE(PRINT_LIST(obj.addTwoNumbers(l1,l2)),"7 0 8");
    }

    {
        ListNode *l1 = CREATE_LIST({2,4,9, 9});
        ListNode *l2 = CREATE_LIST({5,6,4});
        VERIFY_CASE(PRINT_LIST(obj.addTwoNumbers(l1,l2)),"7 0 4 0 1");
    }
}