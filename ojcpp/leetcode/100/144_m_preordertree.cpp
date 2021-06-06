//
// Created by rui zhou on 13/03/19.
//

/*
 * Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
 */

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

namespace lc144 {
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
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ret;
            stack<TreeNode*> right;
            TreeNode *node=root;
            if (!node) return ret;
            while (true) {
                if (node) {
                    ret.emplace_back(node->val);
                    if (node->right!=nullptr) {
                        right.push(node->right);
                    }
                    node=node->left;
                } else {
                    if (!right.empty()) {
                        node=right.top();
                        right.pop();
                    } else {
                        break;
                    }
                }
            }
            return ret;
        }
    };
}


DEFINE_CODE_TEST(144_preordertree)
{
    lc144::Solution obj;
    {
        vector<int> nums{1,2,3};
        TreeNode*root=LCREATE_TREENODE(nums);
        VERIFY_CASE(PRINT_VEC(obj.preorderTraversal(root)),"1 2 3");
    }
}