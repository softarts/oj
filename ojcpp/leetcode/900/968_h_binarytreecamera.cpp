
/*Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

Note:

The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.

2021-05-16
这题看起来很新颖，
3:04 PM
确定使用recursive
使用一个状态来表示每一个node的状态,并分类处理
每一个dfs返回什么？*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
class Solution {
public:
    enum State {NONE=0,COVERED=1,CAMERA=2};
    int ans = 0;
    int minCameraCover(TreeNode* root) {
        if (dfs(root)==State::NONE) {
            ans++;            
        }
        return ans;
    }

    State dfs(TreeNode *node) {
        if (node==nullptr) return State::COVERED; // 叶子结点的子节点视为covered
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        State state;
        if (left==State::NONE || right==State::NONE) {
            state = State::CAMERA;
            ans++;
        } else if (left==State::CAMERA || right==State::CAMERA) {
            state = State::COVERED;
        } else {
            state = State::NONE;
        }
        return state;

    }
};
}
