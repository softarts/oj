//
// Created by Rui Zhou on 2/3/18.
//
/* linkedlist
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 * Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

 自己想出来的思路，对于每个需要SWAP 的NODE, 递归调用SWAPPAIR函数。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 1->2->3  ==> 2->1->3
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace CODECH;
namespace lc024 {
    class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (!head) {
                return nullptr;
            }
            ListNode* a = head;
            ListNode* b = head->next;

            ListNode* next = b?b->next:nullptr;
            if (b) {
                b->next = a;
                if (next) {
                    a->next = swapPairs(next);
                } else {
                    a->next = nullptr;
                }
                return b;
            } else {
                return a;
            }
        }
    };


    //1-2-3-4  =>2-1-4-3
    //* 1->2->3  ==> 2->1->3
    class Solution1 {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (!head) return head;
            if (head && !head->next) return head;
            ListNode *newHead = head->next;
            ListNode *nextHead = newHead->next;
            newHead->next=head;
            head->next=swapPairs(nextHead);
            return newHead;
        }
    };

}


DEFINE_CODE_TEST(024_swap_in_pair)
{
    lc024::Solution1 obj;
    {
        ListNode *head = CREATE_LIST({1,2,3,4});
        ListNode *newHead = obj.swapPairs(head);
        VERIFY_CASE(PRINT_LIST(newHead),"2 1 4 3");
        //PRINT_LIST(newHead);
    }
    {
        ListNode *head = CREATE_LIST({1,2,3});
        ListNode *newHead = obj.swapPairs(head);
        VERIFY_CASE(PRINT_LIST(newHead),"2 1 3");
    }


}