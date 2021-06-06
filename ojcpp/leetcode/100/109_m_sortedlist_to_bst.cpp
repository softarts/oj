//
// Created by rui zhou on 24/03/19.
//

/*
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of
 every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

 转化为一个高度balanced 的tree

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    //要求把left和right都填满的
    class Solution {
    protected:
        ListNode*list;
    public:
        int count(ListNode*node) {
            int count=0;
            while (node) {
                node=node->next;
                count++;
            }
            return count;
        }

        TreeNode*generate(int n) {
            if (n==0)
                return nullptr;
            TreeNode *node=new TreeNode(0);
            node->left = generate(n/2);
            node->val=list->val;
            list=list->next;
            node->right=generate(n-n/2-1);
            return node;
        }

        TreeNode *sortedListToBST(ListNode *head) {
            this->list = head;
            return generate(count(head));
        }
    };
}


DEFINE_CODE_TEST(109_sortedlist_bst)
{
    Solution obj;
    {
        ListNode*nums = CREATE_LIST({-10,-3,0,5,9});
        TreeNode*root=obj.sortedListToBST(nums);
        cout<<TREE_PREORDER(root);
    }
}
