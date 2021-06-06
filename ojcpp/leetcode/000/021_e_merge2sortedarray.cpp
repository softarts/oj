//
// Created by rui zhou on 20/02/19.
//

/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 小心corner case,input=[]
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *prev=nullptr,*head=nullptr,*tmp=nullptr;

        while (l1 && l2) {
            if (!head) {
                head = l1->val<l2->val?(tmp=l1,l1=l1->next,tmp):(tmp=l2,l2=l2->next,tmp);
                prev=head;
            } else {
                prev->next = l1->val<l2->val?(tmp=l1,l1=l1->next,tmp):(tmp=l2,l2=l2->next,tmp);
                prev=prev->next;
            }
        }
        if (!head) {
            head=l1?l1:l2;
        } else {
            prev->next=l1?l1:l2;
        }

        return head;

    }
};

DEFINE_CODE_TEST(021_merge2sortedarray)
{
    Solution obj;
    {
        vector<int> nums1{1,2,4};
        vector<int> nums2{1,3,4};
        ListNode *h1=CREATE_LIST(std::move(nums1));
        ListNode *h2=CREATE_LIST(std::move(nums2));
        VERIFY_CASE(PRINT_LIST(obj.mergeTwoLists(h1,h2)),"1 1 2 3 4 4");
    }
    {
        ListNode *h1=nullptr;
        ListNode *h2=nullptr;
        VERIFY_CASE(PRINT_LIST(obj.mergeTwoLists(h1,h2)),"");
    }

}