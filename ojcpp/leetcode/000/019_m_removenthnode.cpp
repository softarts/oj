//
// Created by rui.zhou on 2/19/2019.
//

/*
 * Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//corner case例如 首个，最后一个，
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head,*fast=head;
        int k=n;
        while (k-->0) {
            fast=fast->next;
        }
        if (fast== nullptr)
            return head->next;
        while (fast->next) {
            slow=slow->next;
            fast=fast->next;
        }
        if (slow->next==fast)
            slow->next = nullptr;
        else
            slow->next = slow->next->next;
        // remove node?
        return head;
    }
};

DEFINE_CODE_TEST(019_rmeoventhnode)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.removeNthFromEnd(head,2)),"1 2 3 5");
    }
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.removeNthFromEnd(head,1)),"1 2 3 4");
    }
    {
        vector<int> nums{1,2,3,4,5};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.removeNthFromEnd(head,5)),"2 3 4 5");
    }
    {
        vector<int> nums{1,2,3,4,5,6,7,8,9,10};
        ListNode *head = CREATE_LIST(std::move(nums));
        VERIFY_CASE(PRINT_LIST(obj.removeNthFromEnd(head,7)),"1 2 3 5 6 7 8 9 10");
    }
}
