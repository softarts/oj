//
// Created by rui.zhou on 3/14/2019.
//

/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace lc086 {
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode lessNode(0);
            ListNode greatNode(0);

            ListNode*great=&greatNode;
            ListNode*less=&lessNode;
            ListNode *cur=head;

            while (cur) {
                if (cur->val < x) {
                    less->next=cur;
                    less=cur;
                } else {
                    great->next=cur;
                    great=great->next;
                }
                cur = cur->next;
            }
            great->next=nullptr;
            less->next=greatNode.next;
            return lessNode.next;
        }
    };
}

DEFINE_CODE_TEST(086_partitionlist)
{
    lc086::Solution obj;
    {
        ListNode *head=CREATE_LIST({1,4,3,2,5,2});
        VERIFY_CASE(PRINT_LIST(obj.partition(head,3)),"1 2 2 4 3 5");
    }
}