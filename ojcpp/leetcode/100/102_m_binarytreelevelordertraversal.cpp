//
// Created by Rui Zhou on 30/3/18.
//

/*
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

 */

#include <codech/codech_def.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#include <codech/algo_common.h>

using namespace CODECH;
using namespace std;
namespace {
    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>>  ret;
            std::deque<TreeNode*> toDo{root};
            int count =1;
            while (!toDo.empty()) {
                vector<int> level;
                int levelCount = 0;
                for (int i=0;i<count;i++) {
                    TreeNode *node = toDo.front();
                    toDo.pop_front();
                    if (node) {
                        level.emplace_back(node->val);
                        toDo.push_back(node->left);
                        toDo.push_back(node->right);
                        levelCount +=2;
                    }
                }
                if (!level.empty())
                    ret.push_back(level);
                count = levelCount;
            }

            return ret;
        }
    };
}



DEFINE_CODE_TEST(102_binarytreelevelordertraversal)
{
    Solution obj;
    {
//        vector<int> nums{3,9,20,null,null,15,7,null,null,null,null};
//        TreeNode* root = LCREATE_TREENODE(nums);
//        cout << PRINT_VVEC(obj.levelOrder(root));
//      VERIFY_CASE(PRINT_VVEC(obj.levelOrder(root)),"3 9 20 15 7 ");
        TreeNode* root = CREATE_TREENODE({3,9,20,null,null,15,7,null,null,null,null});
        VERIFY_CASE(PRINT_VVEC(obj.levelOrder(root)),"3 9 20 15 7 ");
    }
}

