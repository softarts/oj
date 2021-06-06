//
// Created by rui.zhou on 3/16/2019.
//

/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 不难，就花了10分钟
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            deque<TreeNode*> deq{root};
            vector<vector<int>> ret;
            if (!root) return ret;
            int layer=0;

            while (!deq.empty()) {
                vector<TreeNode *> layerNodes;
                vector<int> row;

                while (!deq.empty()) {
                    TreeNode *node = deq.front();
                    deq.pop_front();
                    if (node) {
                        if (node->left)
                            layerNodes.emplace_back(node->left);
                        if (node->right)
                            layerNodes.emplace_back(node->right);
                        row.emplace_back(node->val);
                    }
                }
                if (layer % 2 == 1)
                    std::reverse(row.begin(), row.end());
                layer++;
                ret.emplace_back(row);
                deq.insert(deq.end(), layerNodes.begin(), layerNodes.end());
            }
            return ret;
        }
    };
}