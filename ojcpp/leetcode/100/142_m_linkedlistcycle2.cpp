//
// Created by Rui Zhou on 21/3/18.
//

/*
 * https://leetcode.com/problems/linked-list-cycle-ii/solution/
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space? O(1)




 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace CODECH;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next?fast->next->next:nullptr;
            if (slow!=nullptr && slow==fast) {
                cycle = true;
                break;//return slow;
            }
        }
        if (cycle) {
            ListNode *cur1 = head;
            ListNode *cur2 = fast;  ////worng
            bool flag = true;
            while (cur1 != cur2) {
//                cur1=(cur1->next!=fast)?cur1->next:fast;
//                cur2=(cur2->next!=fast)?cur2->next:head;
                cur1=(cur1!=fast)?cur1->next:fast;
                if (flag) {
                    cur2=cur2->next;
                    flag = false;
                } else {
                    cur2=(cur2!=fast)?cur2->next:head;
                }

            }
            return cur1;
        } else {
            return nullptr;
        }
    }
};

DEFINE_CODE_TEST(142_linkedlist_cycle2)
{
    Solution obj;
//    {
//        ListNode*head  = CREATE_LIST(vector<int>{1});
//        VERIFY_CASE(obj.detectCycle(head),nullptr);
//    }
//    {
//        ListNode*head  = CREATE_LIST({1,2,3,4,5,6,7,8});
//        VERIFY_CASE(obj.detectCycle(head),nullptr);
//    }
//
//    {
//        ListNode*head  = CREATE_LIST({1,2,3,4,5,6,7,8});
//        ListNode* p8 = FIND_LISTNODE(head, 8);
//        ListNode* p3 = FIND_LISTNODE(head, 3);
//        p8->next = p3;
//
//        VERIFY_CASE(obj.detectCycle(head),p3);
//    }

    {
        ListNode*head  = CREATE_LIST({-1,-7,7,-4,19,6,-9,-5,-2});
        ListNode* p2 = FIND_LISTNODE(head, -2);
        ListNode* p5 = FIND_LISTNODE(head, -5);
        p2->next = p5;

        VERIFY_CASE(obj.detectCycle(head),p5);
    }

    //[-1,-7,7,-4,19,6,-9,-5,-2,-5]
    //tail connects to node index 6


}