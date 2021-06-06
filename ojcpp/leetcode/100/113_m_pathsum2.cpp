//
// Created by rui.zhou on 3/9/2019.
//

/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:
TreeNode*root = LCREATE_TREENODE({5,4,8,11,null,13,4,7,2,null,null,5,1});

[
   [5,4,11,2],
   [5,8,4,5]
]

 11.06 pm ->11:18pm wtf!!!
 找出所有path 的sum=target
 但是需要注意退出条件,sum=0而且comb为空的时候
 必须是leaf node!,即left & right都是null
 */

#include <codech/codech_def.h>
#include <numeric>
using namespace std;
using namespace CODECH;
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
    void dfs(TreeNode*node,vector<int>&comb,int target,vector<vector<int>> &ret) {
        if (node==nullptr) {
            return;
        }
        comb.emplace_back(node->val);
        if (node->left==nullptr && node->right==nullptr) {
            int sum=accumulate(comb.begin(),comb.end(),0);
            if (sum==target) {
                ret.emplace_back(comb);
            }
        } else {
            dfs(node->left,comb,target,ret);
            dfs(node->right,comb,target,ret);
        }
        comb.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> comb;
        dfs(root,comb,sum,ret);
        return ret;
    }
};

DEFINE_CODE_TEST(113_pathsum2)
{
    Solution obj;
    {
        TreeNode*root = LCREATE_TREENODE({1});
        vector<vector<int>> exp{{1}};
        VERIFY_CASE(VERIFY_VV(obj.pathSum(root,1),exp),true);
    }
    {
        vector<vector<int>> exp{};
        VERIFY_CASE(VERIFY_VV(obj.pathSum(nullptr,0),exp),true);
    }
    {
        TreeNode*root = LCREATE_TREENODE({1,2});
        vector<vector<int>> exp{};
        VERIFY_CASE(VERIFY_VV(obj.pathSum(root,1),exp),true);
    }

    {
        TreeNode*root = LCREATE_TREENODE({5,4,8,11,null,13,4,7,2,null,null,5,1});
        vector<vector<int>> exp{{5,4,11,2},{5,8,4,5}};
        VERIFY_CASE(VERIFY_VV(obj.pathSum(root,22),exp),true);
    }

}