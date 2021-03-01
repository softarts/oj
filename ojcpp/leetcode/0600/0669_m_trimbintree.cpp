/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

 

Example 1:


Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
Example 2:


Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
Example 3:

Input: root = [1], low = 1, high = 2
Output: [1]
Example 4:

Input: root = [1,null,2], low = 1, high = 3
Output: [1,null,2]
Example 5:

Input: root = [1,null,2], low = 2, high = 4
Output: [2]
 

Constraints:

The number of nodes in the tree in the range [1, 104].
0 <= Node.val <= 104
The value of each node in the tree is unique.
root is guaranteed to be a valid binary search tree.
0 <= low <= high <= 104
*/

//11:41 PM
#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;
namespace {
    class Solution {
    public:
        TreeNode dummy;
        TreeNode *dummyRoot =nullptr;
        TreeNode* trimBST(TreeNode* root, int low, int high) {                 
            helper(&dummy, root, low, high);
            return dummyRoot==nullptr?root:dummyRoot;
        }


        void helper(TreeNode* parent,TreeNode* node, int low, int high) {
            //node;
            if (node==nullptr) return;
            if (node->val < low) {
                parent->left = node->right;
                if (dummyRoot==nullptr) dummyRoot = node->right;
                helper(parent, node->right,low,high);
            } else if (node->val > high) {
                parent->right = node->left;
                if (dummyRoot==nullptr) dummyRoot = node->left;
                helper(parent, node->left,low,high);
            } else {
                helper(node, node->left,low,high);
                helper(node, node->right,low,high);
            }
       }

    };
}