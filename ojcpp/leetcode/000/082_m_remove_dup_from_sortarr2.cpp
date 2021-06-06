//
// Created by rui.zhou on 3/13/2019.
//

/* linkedlist
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
 花了20分钟，主要还是在考虑如何对比前后元素上，确定了先比较当前和下一个元素，不一样就加入当前元素的思路，这样后面就顺利多了
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
using namespace std;
using namespace CODECH;

 namespace lc082 {
     class Solution {
     public:
         ListNode* deleteDuplicates(ListNode* head) {
             ListNode dummy(0);
             ListNode *prev = &dummy;
             if (!head || head->next == nullptr) return head;
             ListNode *cur = head;
             while (cur) {
                 if (cur->next && cur->val != cur->next->val) {
                     prev->next = cur;
                     prev = cur;
                     cur = cur->next;
                 } else {
                     if (!cur->next) {
                         break;
                     } else {
                         int val = cur->val;
                         while (cur && cur->val == val) {
                             cur = cur->next;
                         }
                     }
                 }
             }
             prev->next = cur;
             return dummy.next;
         }
     };
 }

 DEFINE_CODE_TEST(082_remove_dup_sortlist)
{
    lc082::Solution obj;
    {
        ListNode *head=CREATE_LIST({1,2,3,3,4,4,5});
        VERIFY_CASE(PRINT_LIST(obj.deleteDuplicates(head)),"1 2 5");
    }
}
