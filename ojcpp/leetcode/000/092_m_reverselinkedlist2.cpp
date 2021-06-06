//
// Created by rui zhou on 28/02/19.
//

/*
 * Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // use stack
class Solution {
public:
    ListNode* rev2Node(ListNode* a,ListNode*b) {
         ListNode*next=b->next;
         b->next=a;
         a->next=nullptr;
         return next;
    }

    ListNode* revList(ListNode*head,int i) {
        int count=1;
        ListNode*tail=head;
        ListNode *fast=head->next;
        head->next=nullptr;
        while (count<i) {
            ListNode *next=fast->next;
            fast->next=head;
            head=fast;
            fast=next;
            count++;
        }
        tail->next=fast;
        return head;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int i=0;
        ListNode dummy(0);
        dummy.next=head;
        ListNode *tail=&dummy;
        while (++i<m) {
            tail=tail->next;
        }
        ListNode*revHead=revList(tail->next,n-m+1);
        tail->next=revHead;
        return dummy.next;
     }

     ListNode *reverseBetween0(ListNode *head, int m, int n) {
        stack<ListNode*> stack;
        ListNode*cur=head;
        ListNode *tail=nullptr;
        for (int i=1;i<=n;i++) {
            if (i>=m) {
                stack.push(cur);
            } else {
                tail=cur;
            }
            cur=cur->next;
        }

        ListNode dummy(0);
        ListNode *prev=nullptr,*newhead=nullptr;
        if (m!=1) {
            prev=tail;
            newhead=head;
        } else {
            prev=&dummy;
            newhead=dummy.next;
        }

        while (!stack.empty()) {
            ListNode *ptr=stack.top();
            prev->next=ptr;
            stack.pop();
            prev=ptr;
        }
        prev->next=cur;
        return newhead;
     }
 };

//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        ListNode *cur=head,*tail=nullptr;
//        ListNode revdummy(0);
//        ListNode newhead(0);
//        for (int i=1;i<=n;i++) {
//            ListNode*next=cur->next;
//            if (i>=m && i<=n) {
//                ListNode *tmp = revdummy.next;
//                revdummy.next=cur;
//                cur->next=tmp;
//                if (i==n) {
//                    if (tail) {
//                        tail->next=cur;
//                    }
//                }
//            } else {
//                tail=cur;
//            }
//            cur=next;
//        }
//
//    }
//};

DEFINE_CODE_TEST(092_reverselinkedlist2)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.revList(head,5)),"5 4 3 2 1");
    }

    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseBetween(head,2,4)),"1 4 3 2 5");
    }
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseBetween(head,1,5)),"5 4 3 2 1");
    }
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseBetween(head,5,5)),"1 2 3 4 5");
    }
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseBetween(head,1,1)),"1 2 3 4 5");
    }
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseBetween(head,2,2)),"1 2 3 4 5");
    }
    {
        vector<int> nums{5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseBetween(head,1,1)),"5");
    }


}
