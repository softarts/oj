//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 * Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

 */
#include <codech/codech_def.h>
#include <unordered_set>
#include <codech/algo_common.h>

using namespace CODECH;
using namespace std;

namespace {
    // hashmap
    class Solution0 {
    public:
        ListNode *getIntersectionNode0(ListNode *headA, ListNode *headB) {
            unordered_set<ListNode *> nodes;
            while (headA) {
                nodes.insert(headA);
                headA = headA->next;
            }

            while (headB) {
                auto &&iter = nodes.find(headB);
                if (iter != nodes.end()) {
                    return headB;
                }
                headB = headB->next;
            }

            return nullptr;
        }
    };

    class Solution {
    public:
        // O(1) space
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *cur1 = headA;
            ListNode *cur2 = headB;

            while (cur1 != cur2) {
                cur1=cur1?cur1->next:headB;
                cur2=cur2?cur2->next:headA;
            }
            return cur1;
        }
    };

}


DEFINE_CODE_TEST(160_intersection_linkedlist)
{
    Solution obj;
    {
        ListNode *head1 = CREATE_LIST({1,2,3,4,5,6,7,8});
        ListNode *head2 = CREATE_LIST({1,2,3,4,5,6,7,8,9});
        VERIFY_CASE(obj.getIntersectionNode(head1, head2), nullptr);
    }

    {
        ListNode *head1 = CREATE_LIST({11,12,13,14,15});
        ListNode *n1 = FIND_LISTNODE(head1, 15);

        ListNode *head2 = CREATE_LIST({1,2,3,4,5,6,7,8,9});
        ListNode *n2 = FIND_LISTNODE(head2, 5);
        n1->next = n2;

        VERIFY_CASE(obj.getIntersectionNode(head1, head2), n2);
    }

}
