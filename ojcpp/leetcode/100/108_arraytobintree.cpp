//
// Created by Rui Zhou on 10/3/18.
//


/*
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
7:00 pm-
 pick mid point as tree node
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>
#include <vector>

using namespace std;
using namespace CODECH;


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        TreeNode *root = create(0,nums.size()-1, nums);
        return root;
    }
    TreeNode* create(int start, size_t end, vector<int>& nums) {
        if (start>end) {
            return nullptr;
        } else if (start==end) {
            TreeNode*node = new TreeNode(nums[start]);
            return node;
        }

        int mid = start + (end-start)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = create(start, mid-1, nums);
        node->right = create(mid+1, end,nums);
        return node;
    }
};

DEFINE_CODE_TEST(108_arraytotree)
{
    Solution obj;
    vector<int> nums={-10,-3,0,5,9};
    TreeNode *root = obj.sortedArrayToBST(nums);
    TREE_PREORDER(root);
}