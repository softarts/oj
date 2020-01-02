//
// Created by rui zhou on 2019-12-31.
//

/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 */


#include <codech/codech_def.h>

using namespace std;
using namespace CODECH;
namespace {
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    // too slow
    class Solution0 {
    public:
        void reorderList(ListNode* head) {
            if (!head) return;

            deque<ListNode*> dq;
            auto node = head;
            while(node) {
                dq.emplace_back(node);
                node=node->next;
            }

            ListNode* prev = nullptr;
            while (!dq.empty()) {
                if (!dq.empty()) {
                    auto p = dq.front();
                    if (prev)
                        prev->next = p;
                    prev = p;
                    dq.pop_front();
                } else {
                    break;
                }


                if (!dq.empty()) {
                    auto p = dq.back();
                    if (prev)
                        prev->next = p;
                    prev = p;
                    dq.pop_back();
                } else {
                    break;
                }
            }
        }
    };

    // two pointer and reverse
    class Solution {
    public:
        void reorderList(ListNode* head) {
            if (!head || !head->next) return;

            auto *h1=head,*h2=head->next,*l1=h1,*l2=h2;

            // two pointer
            auto slow = head, fast=head;
            ListNode*prev = nullptr;
            while (fast!=nullptr && fast->next!=nullptr) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next; // 2 steps;
            }

            prev->next = nullptr;


            auto reverse_list = [](ListNode* h) {
                ListNode *curr = h;
                ListNode *prev = nullptr;
                while (curr) {
                    auto next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                return prev;
            };

            h2 = reverse_list(slow);

            //105h1 = reverse_list(h1);

            //cout << PRINT_LIST(h1) << endl;
            //cout << PRINT_LIST(h2) << endl;

            auto merge_list = [](ListNode*h1,ListNode*h2) {
                ListNode dummy(0);
                ListNode*prev = &dummy;

                while (h1) {
                    auto h1n = h1?h1->next:nullptr;
                    auto h2n = h2?h2->next:nullptr;
                    prev->next = h1;
                    h1->next = h2;
                    prev = h2;
                    h1=h1n;h2=h2n;
                }

                return dummy.next;

            };
            head = merge_list(h1,h2);
        }

    };


}


DEFINE_CODE_TEST(143_reorderlist)
{
    Solution obj;
    {
        ListNode*head = CREATE_LIST({1,2,3,4,5});
        obj.reorderList(head);
        VERIFY_CASE(PRINT_LIST(head),"1 5 2 4 3");
    }

    {
        ListNode*head = CREATE_LIST({1,2,3,4});
        obj.reorderList(head);
        VERIFY_CASE(PRINT_LIST(head),"1 4 2 3");
    }




}