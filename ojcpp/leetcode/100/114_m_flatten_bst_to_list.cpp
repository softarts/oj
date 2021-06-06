//
// Created by rui.zhou on 3/16/2019.
//

/*
 * Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

题意不是很明确，将左子树全部插入到右子树？

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
 //太精彩的解法了
    class Solution {
    public:
        void flatten(TreeNode* root) {
            if (root) {
                TreeNode*tmp = root->right;
                root->right=root->left;
                root->left=nullptr;
                TreeNode*cur=root;
                while (cur->right) {
                    cur=cur->right;
                }
                cur->right=tmp;
                flatten(root->right);
            }

        }
    };
}

DEFINE_CODE_TEST(114_flatten_tree_list)
{
    Solution obj;
    {
        TreeNode *root=LCREATE_TREENODE({1,2,5,3,4,null,6,null,null,null,null,null,null});
        obj.flatten(root);
        cout << TREE_BYLEVEL(root) <<endl;
    }
}