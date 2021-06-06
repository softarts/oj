//
// Created by rui.zhou on 3/6/2019.
//

/*
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
从inorder和postorder重建binary tree
*/

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 以postorder最后一个元素为root,
//使用一个map来记录inorder中对应的元素的位置，作为inidx，然后计算出nest嵌套的起始位置
class Solution {
public:
    TreeNode *dfs(vector<int>& post,vector<int>& in, int pi,int start, int end) {
        if (start==end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(post[pi]);
        int inidx = map[post[pi]];
        root->right = dfs(post,in,pi-1,inidx+1,end);
        int rightSize=end-(inidx+1);
        root->left = dfs(post,in,pi-rightSize-1,start,inidx); //9,3
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0;i<inorder.size();i++) {
            map[inorder[i]]=i;
        }
        return dfs(postorder,inorder,postorder.size()-1,0,inorder.size());
    }
private:
    unordered_map<int,int> map;
};

DEFINE_CODE_TEST(106_buildbt_inpostorder)
{
    Solution obj;
    {
        vector<int> p{9,15,7,20,3},i{9,3,15,20,7};
        VERIFY_CASE(TREE_PREORDER(obj.buildTree(i,p)),"3 9 20 15 7");
    }

}