package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//不需要
public class Lc0701_insertintobst extends BaseSolution {
    class Solution {
        public TreeNode insertIntoBST(TreeNode root, int val) {
            if (root==null) {
                root = new TreeNode(val);
            } else {
                if (val < root.val) {
                    root.left = insertIntoBST(root.left, val);
                } else {
                    root.right = insertIntoBST(root.right, val);
                }
            }
            return root;
        }
    }
}
