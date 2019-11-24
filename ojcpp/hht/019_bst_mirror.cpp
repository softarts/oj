//
// Created by rui zhou on 2019-11-22.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if (!root)
                return root;
            invertTree(root->left);
            invertTree(root->right);
            TreeNode *tmp=root->left;
            root->left=root->right;
            root->right=tmp;
            return root;
        }
    };
}