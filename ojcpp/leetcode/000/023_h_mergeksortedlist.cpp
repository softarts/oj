//
// Created by rui.zhou on 2/12/2019.
//

/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 这题并不难.套路
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using vt = vector<ListNode*>::value_type ;
        auto comp = [](vt &a, vt &b){
            return a->val > b->val;
        };
        priority_queue<vt,vector<vt>,decltype(comp)> queue(comp);
        for (auto el:lists) {
            if (el)
                queue.push(el);
        }
        ListNode *root=nullptr;
        ListNode*prev=nullptr;
        while (!queue.empty()) {
            ListNode* pNode = queue.top();
            queue.pop();
            if (prev) {
                prev->next = pNode;
            } else {
                root = pNode;
            }
            prev = pNode;
            if (pNode->next) {
                queue.push(pNode->next);
            }
        }
        return root;
    }
};

DEFINE_CODE_TEST(023_mergesortedlist) {
    Solution obj;
    {
        vector<int> l1{1,4,5};
        vector<int> l2{1,3,4};
        vector<int> l3{2,6};
        ListNode*n1=CREATE_LIST(std::move(l1));
        ListNode*n2=CREATE_LIST(std::move(l2));
        ListNode*n3=CREATE_LIST(std::move(l3));
        vector<ListNode*> lists;
        lists.emplace_back(n1);
        lists.emplace_back(n2);
        lists.emplace_back(n3);
        VERIFY_CASE(PRINT_LIST(obj.mergeKLists(lists)),"1 1 2 3 4 4 5 6");
    }
}