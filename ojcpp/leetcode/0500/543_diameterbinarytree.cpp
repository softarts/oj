//
// Created by rui.zhou on 2019/8/30.
//

/*
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
 */

#include <codech/codech_def.h>
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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
         dfs(root);
         return ans>0?ans-1:0;
    }


    int dfs(TreeNode *node) {
        if (!node)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        ans = max(ans,left+right+1);
        return max(left,right)+1;
    }
};


DEFINE_CODE_TEST(543_diameterbst) {
    {
        Solution obj;
        TreeNode *root= CREATE_TREENODE({1,2,3,4,5});
        VERIFY_CASE(obj.diameterOfBinaryTree(root),3);
    }
    {
        Solution obj;

        VERIFY_CASE(obj.diameterOfBinaryTree(nullptr),0);
    }

}
