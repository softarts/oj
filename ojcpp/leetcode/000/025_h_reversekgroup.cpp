//
// Created by rui zhou on 19/02/19.
//

/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
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
using namespace CODECH;
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* next=head;
        int count=0;
        while (next) {
            next=next->next;count++;
        }
        if (k<=1 || k>count)
            return head;
        int loop = count/k;

        ListNode* prevtail = nullptr, *newhead = nullptr;
        for (int i=0;i<loop;i++) {
            prevtail = reverse(prevtail, head, k);
            if (!newhead)
                newhead = head;
            if (prevtail)
                head = prevtail->next;

        }
        return newhead;

    }

    ListNode* reverse(ListNode *prevtail, ListNode *&head, int k) {
        ListNode *tail=head,*prev=tail;
        head=head->next;
        while (k>1) {
            ListNode *tmp=prev;
            prev=head;
            head=head->next;
            prev->next=tmp;
            k--;
        }
        tail->next=head;
        head=prev;

        if (prevtail) {
            prevtail->next = head;
        }
        return tail;  // as the prevtail
    }

};

DEFINE_CODE_TEST(025_reversekgroup)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseKGroup(head,2)),"2 1 4 3 5");

    }
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseKGroup(head,3)),"3 2 1 4 5");

    }

    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseKGroup(head,5)),"5 4 3 2 1");

    }

    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseKGroup(head,1)),"1 2 3 4 5");
    }
    {
        vector<int> nums{};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.reverseKGroup(head,1)),"");

    }

}