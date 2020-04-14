package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

import static java.lang.Math.max;

public class Lc0543_diameterbinarytree extends BaseSolution {
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode(int x) { val = x; }
     * }
     */
    class Solution0 {
        public int diameterOfBinaryTree(TreeNode root) {
            dfs(root);
            return maxdiameter==Integer.MIN_VALUE?0:maxdiameter-1;
        }

        int maxdiameter = Integer.MIN_VALUE;

        int dfs(TreeNode node) {
           if (node==null) return 0;
           var left = dfs(node.left);
           var right = dfs(node.right);
           maxdiameter = max(maxdiameter,left+right+1);
           return max(left+1, right+1);
        }
    }

    @Override
    public boolean test() {
        //TreeNode root = TreeNode.createTree(new ArrayList<Integer>(Arrays.asList(2,1));
        //TreeNode t2 = new TreeNode(2);
        //TreeNode t1 = new TreeNode(1);
        //t2.left = t1;
        //return new Solution().lowestCommonAncestor(t2,t2,t1)==t2;
        return true;
    }

    @Override
    public String name() {return "543 diameter binary tree";}


}
