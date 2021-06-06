//
// Created by rui.zhou on 2/9/2019.
//

/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
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

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
class Solution0 {
public:
    // BST的定义
    // 左子树小于node,右子树大于node,但是还要保证右子树的最小值必须大于node,左子树的最大值必须小于node
    // 即每个递归的时候把最大最小值传递进去
    bool isValidBST0(TreeNode* root) {
        if (!root)
            return false;
        int minval = INT_MAX;
        int maxval = INT_MIN;
        return helper(root,minval,maxval);
    }
    bool helper(TreeNode* root, int &minval, int &maxval) {
        if (!root)
            return true;

        bool result = true;
        if (root->left) {
            minval = min(minval,root->left->val);
            maxval = INT_MIN;
            if (root->left->val<root->val) {
                result = helper(root->left,minval,maxval);
                if (root->val < maxval)
                    return false;
            }
            else {
                return false;
            }
        }
        if (!result)
            return result;

        if (root->right) {
            maxval = max(maxval,root->right->val);
            minval = INT_MAX;
            if (root->right->val>root->val) {
                result = helper(root->right,minval,maxval);
                if (root->val > minval)
                    return false;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

// 将当前的minval和maxval传递到各个子树。
// 太漂亮的代码了
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        int64_t maxval = std::numeric_limits<int64_t>::max();
        int64_t minval = std::numeric_limits<int64_t>::min();
        return dfs(root,minval,maxval);
    }
    bool dfs(TreeNode* root, int64_t minval, int64_t maxval) {
        if (!root)
            return true;
        return (root->val>minval &&
                root->val < maxval &&
                dfs(root->left,minval,root->val) &&
                dfs(root->right,root->val, maxval)
        );
    }
};
DEFINE_CODE_TEST(098_validatebst)
{
    Solution obj;
    {
        TreeNode *root = LCREATE_TREENODE({2,1,3});
        VERIFY_CASE(obj.isValidBST(root),true);
    }
    {
        TreeNode *root = LCREATE_TREENODE({10,5,15,null,null,6,20});
        VERIFY_CASE(obj.isValidBST(root),false);
    }

    {
        TreeNode *root = LCREATE_TREENODE({5,1,4,null,null,3,6});
        VERIFY_CASE(obj.isValidBST(root),false);
    }
    {
        TreeNode *root = LCREATE_TREENODE({1,1});
        VERIFY_CASE(obj.isValidBST(root),false);
    }
    {
        TreeNode *root = LCREATE_TREENODE({2147483647});
        VERIFY_CASE(obj.isValidBST(root),true);
    }

}