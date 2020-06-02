/**
 * Created by rui.zhou on 28 May, 2020
 */
package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

import java.util.*;

//Input: [1,null,2,3]
//1
// \
//  2
// /
//3
//
//Output: [3,2,1]
public class Lc0145_postordertraversal extends BaseSolution {
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode() {}
     *     TreeNode(int val) { this.val = val; }
     *     TreeNode(int val, TreeNode left, TreeNode right) {
     *         this.val = val;
     *         this.left = left;
     *         this.right = right;
     *     }
     * }
     */
    // recursive
    class Solution0 {
        public List<Integer> postorderTraversal(TreeNode root) {
            LinkedList<Integer> ret = new LinkedList<>();
            dfs(root,ret);
            return ret;
        }

        void dfs(TreeNode node, List<Integer> ans) {
            if (node==null) return;
            dfs(node.left,ans);
            dfs(node.right,ans);
            ans.add(node.val);
        }
    }

    // iteratively
    // 套路如下，先把left node全部塞进一个queue里
    // 對於postorder有點難處理，使用一個hashset來保存是否訪問過
    class Solution {
        public List<Integer> postorderTraversal(TreeNode root) {
            LinkedList<Integer> ret = new LinkedList<>();
            LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
            HashSet<TreeNode> visited = new HashSet();
            while (root!=null) {
                queue.offer(root);
                root = root.left;
            }

            while (!queue.isEmpty()) {
                TreeNode node = queue.peekLast();
                if (node!=null) {
                    TreeNode right = node.right;
                    if (!visited.contains(right)) {
                        visited.add(right);
                        while (right != null) {
                            queue.offer(right);
                            right = right.left;
                        }
                    } else {
                        ret.add(node.val);
                        queue.pollLast();
                    }
                }

            }
            return ret;
        }
    }

    @Override
    public boolean test() {
        Solution slu = new Solution();
        TreeNode root = TreeNode.createTree(new ArrayList<Integer>(Arrays.asList(1,null,2,3)));
        slu.postorderTraversal(root);
        return true;
    }
}
