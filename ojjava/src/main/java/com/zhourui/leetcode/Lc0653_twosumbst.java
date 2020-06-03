package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

import java.util.HashSet;

// 和twosum类似，但是如何解决，看了一下所谓的DFS方案，并不觉得有什么优化的地方，依然是遍历每个NODE
// 唯一好处是可以提早退出，
public class Lc0653_twosumbst extends BaseSolution {
    class Solution {
        boolean breakFlag = false;
        boolean ret = false;
        public boolean findTarget(TreeNode root, int k) {
            HashSet<Integer> hs = new HashSet();
            dfs(hs,root, k);
            return ret;
        }

        void dfs(HashSet<Integer> hs, TreeNode node, int target) {
            if (node==null || breakFlag) return;
            int gap = target-node.val;
            if (hs.contains(gap)) {
                ret = true;
                breakFlag = true;
                return;
            }

            hs.add(node.val);
            dfs(hs,node.left,target);
            dfs(hs,node.right,target);
        }
    }
}
