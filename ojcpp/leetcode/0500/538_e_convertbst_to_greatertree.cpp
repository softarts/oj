//
// Created by rui.zhou on 2019/8/29.
//

/*
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
    class Solution {
    public:
        int sum = 0;
        TreeNode* convertBST(TreeNode* root) {
            if (root) {
                convertBST(root->right);
                sum+=root->val;
                root->val = sum;
                convertBST(root->left);
            }
            return root;
        }


    };

}


DEFINE_CODE_TEST(538_bsttogreatertree) {
    {
        Solution obj;
        TreeNode *root= CREATE_TREENODE({2,0,3,-4,1});
        TreeNode *newNode = obj.convertBST(root);
        VERIFY_CASE(TREE_PREORDER(newNode),"5 6 2 6 3");
    }
    {
        Solution obj;
        TreeNode *root= CREATE_TREENODE({5,2,13});
        TreeNode *newNode = obj.convertBST(root);
        VERIFY_CASE(TREE_PREORDER(newNode),"18 20 13");
    }

}
