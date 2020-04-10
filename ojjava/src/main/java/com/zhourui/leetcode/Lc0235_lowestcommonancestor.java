package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import com.zhourui.codech.TreeNode;

// 太傻B了，p和q不按序
public class Lc0235_lowestcommonancestor extends BaseSolution {
    class Solution {
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            if (p.val>q.val) {
                TreeNode tmp = q;
                q = p;p=tmp;
            }

            if (root!=null && root.val>q.val) root=root.left;
            if (root!=null && root.val<p.val) root=root.right;
            if (root==null) {
                return root;
            } else {
                if (root.val>=p.val && root.val<=q.val)
                    return root;
                else {
                    return lowestCommonAncestor(root, p, q);
                }
            }
        }
    }

    @Override
    public boolean test() {
        //TreeNode root = TreeNode.createTree(new ArrayList<Integer>(Arrays.asList(2,1));
        TreeNode t2 = new TreeNode(2);
        TreeNode t1 = new TreeNode(1);
        t2.left = t1;
        return new Solution().lowestCommonAncestor(t2,t2,t1)==t2;
    }

    @Override
    public String name() {return "235 lowest common ancestor";}
}
