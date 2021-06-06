//
// Created by rui.zhou on 2/13/2019.
//
/*
 * Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * 思路， 递归， 需要每个DFS取得如下东西:
 * 返回当前节点下最大sum值的路径，如果小于0，则返回0, 表明向上层节点不要考虑本subpath了
 * 每一次递归都要更新totalmax,使用当前最大sum的路径，以及左右子路径加上本节点
 * totalmax放在成员变量里，可以避免层层传递。
 */

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

namespace {
    class Solution {
    public:
        int totalmax;
        int maxPathSum(TreeNode* root) {
            totalmax = INT_MIN;
            dfs(root);
            return totalmax;
        }

        int dfs(TreeNode *node) { // , int &left, int &m2, int &m3
            if (!node)
                return 0;
            int left = dfs(node->left);
            int right = dfs(node->right);
            int submax = max(left, right);
            //int curmax = max(submax+node->val,0);
            int curmax = submax+node->val;
            totalmax = max(totalmax,curmax);
            totalmax = max(totalmax,left+right+node->val);
            return max(curmax,0);

        }
    };
    class Solution1 {
    public:
        int maxPathSum(TreeNode* root) {
            maxsum = INT_MIN;
            return max(maxsum,dfs(root));
        }
    private:
        int maxsum = INT_MIN;
        int dfs(TreeNode *node) { // , int &left, int &m2, int &m3
            if (!node)
                return 0;
            int val = node->val;
            int left = dfs(node->left);
            int right = dfs(node->right);

            maxsum = max({maxsum,val+left+right,val,val+left,val+right});
            return max({val,val+left,val+right});
        }
    };

}


DEFINE_CODE_TEST(124_h_bstmaxsum) {
    Solution1 obj;
    {
        vector<int> nums{-3,null,null};
        TreeNode *root = LCREATE_TREENODE(nums);
        VERIFY_CASE(obj.maxPathSum(root),-3);
    }

    {
        vector<int> nums{-10,9,20,null,null,15,7,null,null,null,null};
        TreeNode *root = LCREATE_TREENODE(nums);
        VERIFY_CASE(obj.maxPathSum(root),42);
    }

}