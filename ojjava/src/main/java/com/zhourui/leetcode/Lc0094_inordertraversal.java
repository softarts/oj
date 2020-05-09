package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

// 循环确实很怪异，需要先把left都放进stack，然后逐个处理他们的right child
public class Lc0094_inordertraversal extends BaseSolution {
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode(int x) { val = x; }
     * }
     */
    class Solution {
        public List<Integer> inorderTraversal(TreeNode root) {
            List<Integer> ans = new ArrayList();
            Stack<TreeNode> st = new Stack();

            while (root!=null) {
                st.push(root);
                root=root.left;
            }//node = null


            while (!st.isEmpty()) {
                var node = st.peek();
                ans.add(node.val);
                st.pop();

                node=node.right;
                while (node!=null) {
                    st.push(node);
                    node=node.left;
                }
            }
            return ans;
        }
    }
}
