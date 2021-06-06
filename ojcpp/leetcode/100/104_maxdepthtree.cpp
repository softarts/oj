//
// Created by Rui Zhou on 10/3/18.
//

/*
 * Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

6:12 pm->

 */


#include <codech/codech_def.h>
#include <codech/algo_common.h>
using namespace CODECH;
using namespace std;
namespace {
    class Solution0 {
    public:
        int maxDepth(TreeNode* root) {
            int maxDepth = 0;
            int depth = 0;
            maxDepth = traversal(root, maxDepth,depth);
            return maxDepth;
        }

        int traversal(TreeNode *node, int &maxDepth, int depth) {
            if (!node)
                return depth;

            maxDepth=max(maxDepth, traversal(node->left,maxDepth,depth+1));
            maxDepth=max(maxDepth, traversal(node->right,maxDepth,depth+1));

            return maxDepth;
        }
    };

    //
    class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (!root)
                return 0;
            int depth = 0;
            depth = max(depth, 1 + maxDepth(root->left));
            depth = max(depth, 1 + maxDepth(root->right));
            return depth;
        }
    };
}


DEFINE_CODE_TEST(104_maxdepthtree)
{
    Solution obj;
    {
        TreeNode *root = CODECH::CREATE_TREENODE({3, 9, 20, null, null, 15, 7});
        VERIFY_CASE(obj.maxDepth(root),3);
    }
}