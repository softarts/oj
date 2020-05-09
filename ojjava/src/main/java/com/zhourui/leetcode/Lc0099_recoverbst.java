package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

import java.util.ArrayList;
import java.util.Collections;

// BST的中序遍历是有序的，最简单的做法就是把中序结果保存下来，再重新复制
// O（1）的解法有没有,如果说针对两个数位置错误
//
public class Lc0099_recoverbst extends BaseSolution {
    class Solution {
        public void recoverTree(TreeNode root) {
            ArrayList<TreeNode> lst = new ArrayList();
            ArrayList<Integer> vals = new ArrayList();
            inorder(root,lst,vals);
            Collections.sort(vals);
            for (int i=0;i<lst.size();i++) {
                lst.get(i).val = vals.get(i);
            }
        }

        void inorder(TreeNode node, ArrayList<TreeNode> lst, ArrayList<Integer> vals) {
            if (node==null) {
                return;
            }
            inorder(node.left, lst, vals);
            lst.add(node);
            vals.add(node.val);
            inorder(node.right, lst, vals);
        }
    }
}
