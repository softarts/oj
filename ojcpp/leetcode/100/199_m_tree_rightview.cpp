//
// Created by rui.zhou on 3/16/2019.
//

/*
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {

            vector<int> ret;
            if (!root) return ret;
            deque<TreeNode*> deq{root};
            while (!deq.empty()) {
                vector<TreeNode *> layerNodes;
                vector<int> rightview;
                while (!deq.empty()) {
                    TreeNode*node=deq.front();
                    deq.pop_front();
                    if (node) {
                        if (node->left) {
                            layerNodes.emplace_back(node->left);
                        }
                        if (node->right) {
                            layerNodes.emplace_back(node->right);
                        }
                        rightview.emplace_back(node->val);
                    }
                }
                ret.emplace_back(rightview.back());
                copy(layerNodes.begin(),layerNodes.end(),back_inserter(deq));
            }
            return ret;
        }
    };
}

DEFINE_CODE_TEST(199_tree_rightview)
{
    Solution obj;
    {
        TreeNode*root=LCREATE_TREENODE({1,2,3,null,5,null,4,null,null,null,null});
        //vector<int> exp{1,3,4};
        VERIFY_CASE(VERIFY_VEC(obj.rightSideView(root),{1,3,4}),true);
    }
    {
        //TreeNode*root=LCREATE_TREENODE({1,2,3,null,5,null,4,null,null,null,null});
        //vector<int> exp{};
        VERIFY_CASE(VERIFY_VEC(obj.rightSideView(nullptr),{}),true);
    }
}