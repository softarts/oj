//
// Created by rui zhou on 2019-12-02.
//

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;
// 将二叉树转成一个排序的双向链表，不能创建新的节点
//   10
// 6   14
//4 8 12 16
//4-6-8-10-12-14-16
//10:16
namespace {
    class Solution {
    public:
        TreeNode* tolist(TreeNode*root) {
            helper(root);
        }

        TreeNode* helper(TreeNode*root) {
            if (root==nullptr)
                return nullptr;

            TreeNode*left = helper(root->left);
            if (left) {
                left->left = root;
                root->right = left;
            }

            TreeNode*right = helper(root->right);
            if (right) {
                right->right = root;
                root->left = right;
            }
            return root;
        }
    };
}

DEFINE_CODE_TEST(027_bst_to_lst)
{

}

