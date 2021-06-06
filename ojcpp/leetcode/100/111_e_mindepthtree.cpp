//
// Created by rui zhou on 2020-01-01.
//

/*
 * 111. Minimum Depth of Binary Tree
Easy

960

548

Add to List

Share
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
 此题条件太复杂
 只有root, depth=1
 root 有一个child,depth=2(而不是1)
 root为null，depth=0

 只有left && right 都是null的才是leaf node!!!!
 */

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

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
//    class Solution {
//    public:
//        int minDepth(TreeNode* root) {
//            if (!root) return 0;
//            auto lc = minDepth(root->left);
//            auto rc = minDepth(root->right);
//            return min(2,min(lc,rc)+1);
//        }
//
//    };

    class Solution {
    public:
        int mindepth = INT_MAX;

        int minDepth(TreeNode* root) {
            helper(root,1);
            return mindepth==INT_MAX?0:mindepth;
        }

        void helper(TreeNode *node, int c) {
            if (!node) return;
            if (node && !node->left && !node->right) {
                // leaf
                mindepth = min(mindepth, c);
                return;
            }

            helper(node->left, c+1);
            helper(node->right, c+1);
        }

    };
}

DEFINE_CODE_TEST(111_mindepthtree)
{
    {
        Solution obj;
        TreeNode*root=CREATE_TREENODE({1});
        VERIFY_CASE(obj.minDepth(root),1);
    }


    {
        Solution obj;
        TreeNode*root=CREATE_TREENODE({1,2});
        VERIFY_CASE(obj.minDepth(root),2);
    }
    {
        Solution obj;
        TreeNode *root = CREATE_TREENODE({3,9,20,null,null,15,7});
        VERIFY_CASE(obj.minDepth(root),2);
    }
    {
        Solution obj;
        VERIFY_CASE(obj.minDepth(nullptr),0);
    }

}

