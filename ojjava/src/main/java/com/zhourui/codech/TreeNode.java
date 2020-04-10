package com.zhourui.codech;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }


    public static TreeNode createTree(ArrayList<Integer> arr) {
        TreeNode root=new TreeNode(arr.get(0));
        LinkedList<TreeNode> toDo=new LinkedList(Arrays.asList(root));

        int idx = 0;
        while (!toDo.isEmpty()) {
            TreeNode parent = toDo.getFirst();
            toDo.pop();
            idx++;
            var left = arr.get(idx);
            if (left!=null) {
                parent.left = new TreeNode(left);
                toDo.push(parent.left);
            } else {
                parent.left = null;
            }

            // right
            idx++;
            var right = arr.get(idx);
            if (right!=null) {
                parent.right = new TreeNode(right);
                toDo.push(parent.right);
            } else {
                parent.right = null;
            }
        }
        return root;
    }
}



//TreeNode* LCREATE_TREENODE(const std::vector<int> &list)
//        {
//        TreeNode *root = new TreeNode(list[0]);
//        std::deque<TreeNode*> toDo{root};
//
//        //for (size_t i=0; i < list.size(); i++) {
//        int idx = 0;
//        while (!toDo.empty()) {
//        TreeNode *parent = toDo.front();
//        toDo.pop_front();
//        idx++;
//        int v1 = list[idx];
//        if (v1 != null) {
//        parent->left = new TreeNode(v1);
//        toDo.push_back(parent->left);
//        } else {
//        parent->left = nullptr;
//        }
//
//
//        idx++;
//        int v2 = list[idx];
//        if (v2 != null) {
//        parent->right = new TreeNode(v2);
//        toDo.push_back(parent->right);
//        } else {
//        parent->right = nullptr;
//        }
//
//        }
//        return root;
//        }