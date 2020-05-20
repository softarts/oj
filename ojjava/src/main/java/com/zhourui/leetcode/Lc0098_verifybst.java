package com.zhourui.leetcode;

import com.zhourui.codech.TreeNode;

//验证二叉树
// 特点就是左tree<node<right
// 但是注意传导性,翻了下答案，确实需要传入一个最大最小值,而且只需要检查本身node
public class Lc0098_verifybst {
    class Solution {
        public boolean isValidBST(TreeNode root) {
            return helper(root,Long.MIN_VALUE,Long.MAX_VALUE);
        }

        boolean helper(TreeNode root,long minv, long maxv) {
            if (root==null) return true;

            return (root.val > minv && root.val <maxv)
                    && helper(root.left,minv,root.val)
                    && helper(root.right,root.val,maxv);
        }
    }
}
