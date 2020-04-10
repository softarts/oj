package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

import static java.lang.Math.max;

//java8 nested, lambda 都不是支持得很好
public class Lc0104_maxdepthoftree extends BaseSolution {
    class Solution {
        public int maxDepth(TreeNode root) {
            if (root==null) return 0;
            int leftDepth = maxDepth(root.left);
            int rightDepth = maxDepth(root.right);
            return max(leftDepth+1, rightDepth+1);
        }


    }
}
