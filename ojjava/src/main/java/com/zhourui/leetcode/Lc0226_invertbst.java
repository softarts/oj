package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

public class Lc0226_invertbst extends BaseSolution {
    public TreeNode invertTree(TreeNode root) {
        if (root==null) return root;
        invertTree(root.left);
        invertTree(root.right);
        TreeNode tmp = root.left;
        root.left=root.right;
        root.right=tmp;
        return root;
    }
}


/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *tmp=root->left;
        root->left=root->right;
        root->right=tmp;
        return root;
    }
};
 */