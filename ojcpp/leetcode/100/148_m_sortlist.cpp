//
// Created by rui zhou on 15/04/18.
//

/*
 *https://leetcode.com/problems/sort-list/description/
 * Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

 参见yuanbin p436
 使用merge sort,首先得到链表长度
 用常规的方法难以移动node，因为有前后关系


 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 */

#include <codech/codech_def.h>
//#include <codech/algo_common.h>
//#include <list>
using namespace std;
using namespace CODECH;

namespace lc148 {
    class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if (head==nullptr)
                return head;
            ListNode *node = head;
            int length = 0;
            while (node) {
                node=node->next;length++;
            }
            return sortHelper(head, length);
        }

        ListNode* sortHelper(ListNode* head, int length) {
            if (head==nullptr || length<=0) // to make next null ptr
                return head;

            int count = 1;
            ListNode *midNode = head;
            while (count < length/2) {
                midNode = midNode->next;
                count++;
            }
            ListNode *rl = sortHelper(midNode->next,length - length/2);
            midNode->next = nullptr;
            ListNode *ll = sortHelper(head,length/2);
            return mergeList(ll,rl);
        }

        ListNode *mergeList(ListNode*a, ListNode*b) {
            ListNode* dummy = new ListNode(0);
            ListNode *lastNode = dummy;
            while (a && b) {
                if (a->val < b->val) {
                    lastNode->next = a;a=a->next;
                } else {
                    lastNode->next = b;b=b->next;
                }
                lastNode=lastNode->next;lastNode->next=nullptr;
            }
            lastNode->next = (a!=nullptr?a:b);
            lastNode = dummy->next;
            delete dummy;
            return lastNode;
        }
    };
    // merge
    class Solution1 {
    public:
        ListNode *merge(ListNode *a,ListNode*b) {
            ListNode dummy(0);
            ListNode*prev=&dummy;
            while (a&&b) {
                if (a->val<b->val) {
                    prev->next=a;a=a->next;
                } else {
                    prev->next=b;b=b->next;
                }
                prev=prev->next;
            }
            prev->next=a?a:b;
            return dummy.next;
        }

        ListNode* sortList(ListNode* head) {
            if (!head || head->next==nullptr)
                return head;
            ListNode*fast=head->next;
            ListNode*slow=head;
            while (fast && fast->next) {
                slow=slow->next;
                fast=fast->next->next;
            }
            ListNode *l2=slow->next;
            ListNode *l1=head;
            slow->next=nullptr;  //这个很重要，必须设置为nullptr
            l1=sortList(l1);
            l2=sortList(l2);
            return merge(l1,l2);
        }
    };
}



DEFINE_CODE_TEST(148_sortlist)
{
    lc148::Solution1 obj;
    {
        ListNode *head = CREATE_LIST({4,2,1,3});
        VERIFY_CASE(PRINT_LIST(obj.sortList(head)),"1 2 3 4");
    }
    {
        ListNode *head = CREATE_LIST({4,7,8,1,3,9,12,102});
        VERIFY_CASE(PRINT_LIST(obj.sortList(head)),"1 3 4 7 8 9 12 102");
    }


}