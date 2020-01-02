//
// Created by rui zhou on 2020-01-01.
//

/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
        bool hasPathSum(TreeNode* root, int sum) {
            return helper(root,sum,0);
        }


        bool helper(TreeNode *node, int target, int sum) {
            if (node && !node->left && !node->right) {
                return sum+node->val == target;
            }

            if (node && node->left) {
                auto ret = helper(node->left,target,sum+node->val);
                if (ret) return true;
            }

            if (node&& node->right) {
                auto ret = helper(node->right,target,sum+node->val);
                if (ret) return true;
            }
            return false;
        }
    };
}