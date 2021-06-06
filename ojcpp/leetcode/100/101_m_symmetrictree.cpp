//
// Created by Rui Zhou on 10/3/18.
//

/*
 * https://leetcode.com/problems/symmetric-tree/description/
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
easy->
 4:58 pm


 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <deque>

using namespace CODECH;
using namespace std;
namespace {
    // a more elegant solution, recursive
    class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (root) {
                return dfs(root->left,root->right);
            }
            return true;
        }
        bool dfs(TreeNode*a, TreeNode*b) {
            if (a && b) {
                return (a->val==b->val) &&
                    dfs(a->left,b->right) &&
                    dfs(a->right,b->left);
            } else {
                return (a==nullptr && b==nullptr );
            }
        }
    };

    // 按层遍历左右子树，然后每次从树上拉出下一个节点进行比较
    class Solution0 {
    public:
        bool isSymmetric(TreeNode* root) {

            deque<TreeNode*> left = {root->left};
            deque<TreeNode*> right = {root->right};
            bool isSym = true;// root->left->val == root->right->val;

            while (!left.empty() && !right.empty()) {
                TreeNode *lt = left.front();
                TreeNode *rt = right.front();
                left.pop_front();
                right.pop_front();

                if (lt && rt && lt->val==rt->val) {
                    left.push_back(lt->left);
                    left.push_back(lt->right);
                    right.push_back(rt->right);
                    right.push_back(rt->left);
                } else if (!lt || !rt) {
                    if (!lt && !rt) {
                        //break;
                    } else {
                        isSym = false;
                        break;
                    }
                } else {
                    isSym = false;
                    break;
                }
            }
            return isSym;
        }
    };
}





DEFINE_CODE_TEST(101_symmetric)
{
    Solution obj;
    {
        TreeNode *root = CODECH::CREATE_TREENODE({1, 2, 2, 3, 4, 4, 3});
        VERIFY_CASE(obj.isSymmetric(root),true);
    }
    {
        TreeNode *root2 = CODECH::CREATE_TREENODE({1, 2, 2, 3, 4, 4, 5});
         VERIFY_CASE(obj.isSymmetric(root2),false);
    }
    {
        TreeNode *root3 = CODECH::CREATE_TREENODE({1, 2, 2, 0, 3, 0, 3});
        VERIFY_CASE(obj.isSymmetric(root3),false);
    }
    {
        TreeNode *root4 = CODECH::CREATE_TREENODE({9, -42, -42, 0, 76, 76, 0, 0, 0, 0, 13, 0, 13, 0, 0});
        VERIFY_CASE(obj.isSymmetric(root4),false);
    }

}