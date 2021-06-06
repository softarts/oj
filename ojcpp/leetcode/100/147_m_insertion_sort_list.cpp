//
// Created by rui.zhou on 3/15/2019.
//

/* sort
 * Sort a linked list using insertion sort.

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list


Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace lc147 {
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
        ListNode* insertionSortList(ListNode* head) {
            ListNode dummy(INT_MIN);
            auto dummyAddr=&dummy;
            while (head) {
                auto n = head->next;
                int val=head->val;
                auto d=dummyAddr;
                while (d->next && val>d->next->val) {
                    d=d->next;
                }
                auto dn = d->next;
                head->next = dn;
                d->next = head;
                head = n;
            }
            return dummy.next;
        }
    };

    class Solution1 {
    public:
        ListNode* insertionSortList(ListNode* head) {
            ListNode dummy(INT_MIN);
            while (head) {
                ListNode*d=&dummy;
                ListNode*hn=head->next;
                int val = head->val;
                while (d->next && val>d->next->val) {
                    d=d->next;
                } // found val < d->next->val;
                ListNode *dn=d->next;
                d->next=head;
                head->next=dn;
                head=hn;
            }
            return dummy.next;
        }
    };
}

DEFINE_CODE_TEST(147_insertion_sort_list)
{
    lc147::Solution1 obj;
    {
        ListNode*head=CREATE_LIST({4,2,1,3});
        VERIFY_CASE(PRINT_LIST(obj.insertionSortList(head)),"1 2 3 4");
    }
}