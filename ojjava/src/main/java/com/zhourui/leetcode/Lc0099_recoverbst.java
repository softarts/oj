package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

// BST的中序遍历是有序的，最简单的做法就是把中序结果保存下来，再重新复制
// O（1）的解法有没有,如果说针对两个数位置错误
// 实则就是针对inorder遍历，看看和上一个node有无冲突。(如果只有2个node有问题)
public class Lc0099_recoverbst extends BaseSolution {
    class Solution0 {
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

    // O(1) space
    class Solution {
        TreeNode prev;
        TreeNode first,second;
        public void recoverTree(TreeNode root) {
            //prev = root;
            inorder(root);
            int temp=first.val;
            first.val=second.val;
            second.val=temp;
        }

        void inorder(TreeNode node) {
            if (node==null) {
                return;
            }
            inorder(node.left);
            if (prev!=null && node.val < prev.val) {
                if (first==null) first=prev;
                second=node;// 要交换的两个node,一个是prev,一个是node本身
            }
            prev = node;
            inorder(node.right);
        }
    }

    @Override
    public boolean test() {
        //[1,3,null,null,2]
        //TreeNode root=TreeNode.createTree(new ArrayList<>(Arrays.asList(1,3,null,null,2)));
        //new Solution().recoverTree(root);

        TreeNode root=TreeNode.createTree(new ArrayList<>(Arrays.asList(3,1,4,null,null,2)));
        new Solution().recoverTree(root);

        return true;
    }
}
