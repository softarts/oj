//
// Created by rui zhou on 2020-01-01.
//

/*
 * Balanced Binary Tree
Easy

1649

142

Add to List

Share
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            int count;
            return helper(root,count);
        }

        bool helper(TreeNode* node, int &count) {
            if (!node) return true;

            int lc=0,rc=0;
            if (!helper(node->left,lc)) return false;
            if (!helper(node->right,rc)) return false;

            if (abs(lc-rc) > 1) {
                return false;
            } else {
                count = max(lc,rc)+1;
                return true;
            }
        }
    };
}

