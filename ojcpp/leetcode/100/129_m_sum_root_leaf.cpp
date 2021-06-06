//
// Created by rui.zhou on 3/16/2019.
//

/*https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
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
 // 就是使用常规的DFS，但到达叶子的时候计算sum
    class Solution {
    public:
        int sumNumbers(TreeNode* root) {
            int64_t sum=0;
            dfs(root,0,sum);
            return sum;
        }

        void dfs(TreeNode *root,int64_t path, int64_t &sum) {
            if (!root) {
                return;
            }
            path=path*10+root->val;
            if (!root->left && !root->right) {
                sum+=path;
            } else {
                dfs(root->left,path,sum);
                dfs(root->right,path,sum);
            }
        }
    };
}

DEFINE_CODE_TEST(129_sum_root_leaf)
{
    Solution obj;
    {
        TreeNode*root=LCREATE_TREENODE({4,9,0,5,1,null,null,null,null,null,null});
        VERIFY_CASE(obj.sumNumbers(root),1026);

    }
}