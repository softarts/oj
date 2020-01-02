//
// Created by rui zhou on 2019-12-31.
//

/*
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> ans;
            vector<TreeNode*> next{root};
            helper(next,ans);
            return ans;
        }


        void helper(vector<TreeNode*> &layer, vector<vector<int>> &ans) {
            if (layer.empty()) {
                return;
            }

            vector<TreeNode*> next;
            bool flag = false;
            for (auto &it:layer) {
                if (it) {
                    if (it->left)
                        next.emplace_back(it->left);
                    if (it->right)
                        next.emplace_back(it->right);
                    flag = true;
                }

            }
            helper(next,ans);
            if (flag) {
                ans.emplace_back(vector<int>());
                vector<int> &back = ans.back();
                for (auto &it:layer) {
                    if (it)
                        back.emplace_back(it->val);
                }
            }
        }
    };
}